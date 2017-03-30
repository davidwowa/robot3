/*
 * core.cpp
 *
 *  Created on: 17.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include "iostream"
#include <stdio.h>

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../drive/drive.h"
#include "../sonar/sonar.h"
#include "../config/config.h"
#include "../servo/servo.h"

#include "../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../lib/WiringPi/wiringPi/softPwm.h"

#include "../../lib/HC-SR04-Raspberry-Pi-C-/libSonar.h"

using namespace std;

void init(void);
void run(void);
int get_speed(int minimal_distance);
int is_running();

int current_pointer = FORWARD;

void init() {
	system("sudo kill $(pidof python)");
	system("python /home/pi/Pimoroni/scrollphat/examples/sine.py &");

	init_drive();
	init_sonar();
	init_servo();
	move_center_x();
	move_center_y();
}

void run() {
	int distance_m = get_distance();

	cout << "Distance on middle sensor is " << distance_m << " cm." << endl;
	cout << "---" << endl;

	int current_speed = get_speed(distance_m);

	if (distance_m <= MAX_WALL_DISTANCE_1) {
		stop();
		move_left();
		int l = get_distance();
		move_center_x();
		int c = get_distance();
		move_right();
		int r = get_distance();

		if (l < c && r < c) {
			if (l < r) {
				turn_right(current_speed);
				move_center_x();
			} else {
				turn_left(current_speed);
				move_center_x();
			}
		} else {
			drive_forward(current_speed);
		}
	}
}

int main(void) {
	init();
	for (int i = 100; i > 0; i--) {
		run();
	}
	exit(EXIT_SUCCESS);
	return -1;
}

int get_speed(int minimal_distance) {
	int result = SPEED_1;
	if (minimal_distance >= MAX_WALL_DISTANCE_3) {
		result = SPEED_3;
	}
	if (minimal_distance >= MAX_WALL_DISTANCE_2
			&& minimal_distance < MAX_WALL_DISTANCE_3) {
		result = SPEED_2;
	}
	if (minimal_distance >= 0 && minimal_distance < MAX_WALL_DISTANCE_1) {
		result = SPEED_1;
	}
	cout << "current speed is " << result << endl;
	return result;
}

int is_running() {
	FILE *run_config;
	int is_run = 0;

	run_config = fopen("/home/pi/robot3/config/core", "r");
	if (run_config) {
		fscanf(run_config, "%d", &is_run);
		fclose(run_config);
	}
	return is_run;
}

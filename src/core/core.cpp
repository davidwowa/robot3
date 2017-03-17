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
	init_drive();
	init_sonar();
}

void run() {

	int distance_m = get_distance_m();
	int distance_r = get_distance_r();
	int distance_l = get_distance_l();
	int distance_b = get_distance_b();

	cout << "Distance on middle sensor is " << distance_m << " cm." << endl;
	cout << "Distance on right  sensor is " << distance_r << " cm." << endl;
	cout << "Distance on left   sensor is " << distance_l << " cm." << endl;
	cout << "Distance on back   sensor is " << distance_b << " cm." << endl;
	cout << "---" << endl;

	int current_minmal_distance = get_minimal_distance(distance_m, distance_r,
			distance_l);

	int current_speed = get_speed(current_minmal_distance);

	if (FORWARD == current_pointer) {
		if (distance_m > MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			drive_forward(current_speed);
			current_pointer = FORWARD;
		}
		if (distance_m < MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r < MAX_WALL_DISTANCE_1) {
			turn_left(current_speed);
			current_pointer = TURN_LEFT;
		}
		if (distance_m < MAX_WALL_DISTANCE_1 && distance_l < MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			turn_right(current_speed);
			current_pointer = TURN_RIGHT;
		}
		if (distance_m < MAX_WALL_DISTANCE_1 && distance_l < MAX_WALL_DISTANCE_1
				&& distance_r < MAX_WALL_DISTANCE_1) {
			drive_backward(current_speed);
			current_pointer = BACKWARD;
		}
	}

	if (BACKWARD == current_pointer) {
		if (distance_m < MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r < MAX_WALL_DISTANCE_1) {
			turn_left(current_speed);
			current_pointer = TURN_LEFT;
		}
		if (distance_m < MAX_WALL_DISTANCE_1 && distance_l < MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			turn_right(current_speed);
			current_pointer = TURN_RIGHT;
		}
		if (distance_m > MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r < MAX_WALL_DISTANCE_1) {
			turn_left(current_speed);
			current_pointer = TURN_LEFT;
		}
		if (distance_m > MAX_WALL_DISTANCE_1 && distance_l < MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			turn_right(current_speed);
			current_pointer = TURN_RIGHT;
		}
	}

	if (TURN_LEFT == current_pointer) {
		if (distance_m > MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			drive_forward(current_speed);
			current_pointer = FORWARD;
		}
	}

	if (TURN_RIGHT == current_pointer) {
		if (distance_m > MAX_WALL_DISTANCE_1 && distance_l > MAX_WALL_DISTANCE_1
				&& distance_r > MAX_WALL_DISTANCE_1) {
			drive_forward(current_speed);
			current_pointer = FORWARD;
		}
	}

	if (FORWARD == current_pointer) {
		if (distance_m > MAX_WALL_DISTANCE_1) {
			if (distance_l < MAX_WALL_DISTANCE_1) {
				turn_right(current_speed);
				current_pointer = TURN_RIGHT;
			}
			if (distance_r < MAX_WALL_DISTANCE_1) {
				turn_left(current_speed);
				current_pointer = TURN_LEFT;
			}
		} else {
			current_pointer = BACKWARD;
		}
	}

	if (BACKWARD == current_pointer) {
		if (distance_b > MAX_WALL_DISTANCE_1) {
			if (distance_l < MAX_WALL_DISTANCE_1) {
				turn_left(current_speed);
				current_pointer = TURN_LEFT;
			}
			if (distance_r < MAX_WALL_DISTANCE_1) {
				turn_right(current_speed);
				current_pointer = TURN_RIGHT;
			}
		} else {
			current_pointer = BACKWARD;
		}
	}
}

int main(void) {
	init();
	for (int i = 100000; i < 0; i--) {
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

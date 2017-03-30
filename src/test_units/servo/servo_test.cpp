/*
 * servo_test.cpp
 *
 *  Created on: 30.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <iostream>
#include <string>

#include <stdlib.h>

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../../lib/WiringPi/wiringPi/softPwm.h"

#include "gpio_servo.h"
#include "servo.h"

using namespace std;

int main() {
	if (wiringPiSetup() == -1) {
		fprintf(stdout, "wiringPi error: %s\n", strerror(errno));
		return 1;
	}

	pinMode(SERVO_1, OUTPUT);
	pinMode(SERVO_2, OUTPUT);

	digitalWrite(SERVO_1, LOW);
	digitalWrite(SERVO_2, LOW);

	softPwmCreate(SERVO_1, 0, 200);
	softPwmCreate(SERVO_2, 0, 200);

	system("sudo kill $(pidof python)");
	system(
			"python /home/pi/Pimoroni/scrollphat/examples/scroll-text-forever.py TEST_SERVO&");

	// 11-center, 14-left, 8-right
	// 0-up, 9-center, 13-down 

	for (int var = 0; var < 4; ++var) {

		for (int var = 0; var < SERVO_LEFT; ++var) {
			softPwmWrite(SERVO_1, SERVO_LEFT);
			delay(SERVO_DELAY);
		}

		for (int var = 0; var < SERVO_DOWN; ++var) {
			softPwmWrite(SERVO_2, SERVO_DOWN);
			delay(SERVO_DELAY);
		}

		for (int var = 0; var < SERVO_UP; ++var) {
			softPwmWrite(SERVO_2, SERVO_UP);
			delay(SERVO_DELAY);
		}

		for (int var = 0; var < SERVO_CENTER_X; ++var) {
			softPwmWrite(SERVO_1, SERVO_CENTER_X);
			delay(SERVO_DELAY);
		}

		for (int var = 0; var < SERVO_CENTER_Y; ++var) {
			softPwmWrite(SERVO_2, SERVO_CENTER_Y);
			delay(SERVO_DELAY);
		}

		for (int var = 0; var < SERVO_RIGHT; ++var) {
			softPwmWrite(SERVO_1, SERVO_RIGHT);
			delay(SERVO_DELAY);
		}

		for (int var = 0; var < SERVO_UP; ++var) {
			softPwmWrite(SERVO_2, SERVO_UP);
			delay(SERVO_DELAY);
		}

		for (int var = 0; var < SERVO_DOWN; ++var) {
			softPwmWrite(SERVO_2, SERVO_DOWN);
			delay(SERVO_DELAY);
		}
	}
}

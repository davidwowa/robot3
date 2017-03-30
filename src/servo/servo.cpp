/*
 * servo.cpp
 *
 *  Created on: 30.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <stdlib.h>

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../../lib/WiringPi/wiringPi/softPwm.h"

#include "gpio_servo.h"
#include "servo.h"

using namespace std;

void init_wiringPi(void) {
	if (wiringPiSetup() == -1) {
		fprintf(stdout, "wiringPi error: %s\n", strerror(errno));
	}
	pinMode(SERVO_1, OUTPUT);
	pinMode(SERVO_2, OUTPUT);

	digitalWrite(SERVO_1, LOW);
	digitalWrite(SERVO_2, LOW);
}

void init_PWM(void) {
	softPwmCreate(SERVO_1, 0, 200);
	softPwmCreate(SERVO_2, 0, 200);
}

void init_servo(void) {
	init_wiringPi();
	init_PWM();
}

void move_left(void) {
	for (int var = 0; var < SERVO_LEFT; ++var) {
		softPwmWrite(SERVO_1, SERVO_LEFT);
		delay(SERVO_DELAY);
	}
}
void move_right(void) {
	for (int var = 0; var < SERVO_RIGHT; ++var) {
		softPwmWrite(SERVO_1, SERVO_RIGHT);
		delay(SERVO_DELAY);
	}
}
void move_center_x(void) {
	for (int var = 0; var < SERVO_CENTER_X; ++var) {
		softPwmWrite(SERVO_1, SERVO_CENTER_X);
		delay(SERVO_DELAY);
	}
}
void move_up(void) {
	for (int var = 0; var < SERVO_UP; ++var) {
		softPwmWrite(SERVO_2, SERVO_UP);
		delay(SERVO_DELAY);
	}
}
void move_down(void) {
	for (int var = 0; var < SERVO_DOWN; ++var) {
		softPwmWrite(SERVO_2, SERVO_DOWN);
		delay(SERVO_DELAY);
	}
}
void move_center_y(void) {
	for (int var = 0; var < SERVO_CENTER_Y; ++var) {
		softPwmWrite(SERVO_2, SERVO_CENTER_Y);
		delay(SERVO_DELAY);
	}
}

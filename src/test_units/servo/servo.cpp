/*
 * servo.cpp
 *
 *  Created on: 17.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../../lib/WiringPi/wiringPi/softPwm.h"

#include "gpio_servo.h"
#include "servo.h"

using namespace std;

int main() {
	if (wiringPiSetup() == -1) {
		fprintf(stdout, "oops: %s\n", strerror(errno));
		return 1;
	}

	pinMode(SERVO_1, OUTPUT);
	pinMode(SERVO_2, OUTPUT);

	digitalWrite(SERVO_1, LOW);
	digitalWrite(SERVO_2, LOW);

	softPwmCreate(SERVO_1, 0, 200);
	softPwmCreate(SERVO_2, 0, 200);

	int value = 15;

	for (int var = 0; var < value; ++var) {
		fprintf(stdout, "->: %d\n", var);
		softPwmWrite(SERVO_1, var);
		softPwmWrite(SERVO_2, var);
		delay(100);

	}
	for (int var = value; var > 0; --var) {
		fprintf(stdout, "<-: %d\n", var);
		softPwmWrite(SERVO_1, var);
		softPwmWrite(SERVO_2, var);
		delay(100);
	}
}

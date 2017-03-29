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

#include <stdlib.h>

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../../lib/WiringPi/wiringPi/softPwm.h"

#include "gpio_servo.h"
#include "servo.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (wiringPiSetup() == -1) {
		fprintf(stdout, "wiringPi error: %s\n", strerror(errno));
		return 1;
	}

	pinMode(SERVO_1, OUTPUT);
	pinMode(SERVO_2, OUTPUT);

	digitalWrite(SERVO_1, LOW);
	digitalWrite(SERVO_2, LOW);

	softPwmCreate(SERVO_1, 0, 400);
	softPwmCreate(SERVO_2, 0, 400);

	int value = 20;
	int value2 = 9;
	int dly = 20;

	int stop = 0;

	system("kill $(pidof python)");
	system(
			"python /home/pi/Pimoroni/scrollphat/examples/scroll-text-forever.py TEST 1&");

	for (int var = 0; var < (int) argv[0]; ++var) {
		softPwmWrite(SERVO_1, var);
	}

	system("kill $(pidof python)");
	system(
			"python /home/pi/Pimoroni/scrollphat/examples/scroll-text-forever.py TEST 2&");

	for (int var = 0; var < (int) argv[1]; ++var) {
		softPwmWrite(SERVO_2, var);
	}
}

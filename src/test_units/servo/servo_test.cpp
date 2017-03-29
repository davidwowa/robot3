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

int main(int argc, char* argv[]) {
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

	int dly = 15;

	std::string a = argv[1];
	std::string b = argv[2];

	int x = std::stoi(a);
	int y = std::stoi(b);
	cout << x << endl;
	cout << y << endl;

	system("kill $(pidof python)");
	system(
			"python /home/pi/Pimoroni/scrollphat/examples/scroll-text-forever.py TEST_1&");

	if (x >= 0) {
		for (int var = 0; var < x; ++var) {
			softPwmWrite(SERVO_1, HIGH);
			delay(dly);
		}
		softPwmWrite(SERVO_1, LOW);
	} else {
		for (int var = (x * (-1)); var > 0; --var) {
			softPwmWrite(SERVO_1, HIGH);
			delay(dly);
		}
		softPwmWrite(SERVO_1, LOW);
	}

	system("kill $(pidof python)");
	system(
			"python /home/pi/Pimoroni/scrollphat/examples/scroll-text-forever.py TEST_2&");

	if (y >= 0) {
		for (int var = 0; var < y; ++var) {
			softPwmWrite(SERVO_2, HIGH);
			delay(dly);
		}
		softPwmWrite(SERVO_2, LOW);
	} else {
		for (int var = (y * (-1)); var > 0; --var) {
			softPwmWrite(SERVO_2, HIGH);
			delay(dly);
		}
		softPwmWrite(SERVO_2, LOW);
	}
}

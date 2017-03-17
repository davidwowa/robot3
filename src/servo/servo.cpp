/*
 * servo.cpp
 *
 *  Created on: 17.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include "gpio_servo.h"
#include "servo.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../lib/WiringPi/wiringPi/softServo.h"

int main() {
	if (wiringPiSetup() == -1) {
		fprintf(stdout, "oops: %s\n", strerror(errno));
		return 1;
	}

	softServoSetup(SERVO_1, SERVO_2, 2, 3, 4, 5, 6, 7);

	softServoWrite(SERVO_1, 500);
	softServoWrite(SERVO_2, 500);
	/*
	 softServoWrite (1, 1000) ;
	 softServoWrite (2, 1100) ;
	 softServoWrite (3, 1200) ;
	 softServoWrite (4, 1300) ;
	 softServoWrite (5, 1400) ;
	 softServoWrite (6, 1500) ;
	 softServoWrite (7, 2200) ;
	 */

	for (;;)
		delay(10);

}

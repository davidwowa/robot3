/*
 * sonar.cpp
 *
 *  Created on: 17.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#include <iostream>

#include "sonar.h"
#include "gpio_sonar.h"

#include "../../lib/HC-SR04-Raspberry-Pi-C-/libSonar.h"

#include "../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../lib/WiringPi/wiringPi/softPwm.h"

using namespace std;

Sonar sonar;

void init_sonar() {

	if (wiringPiSetup() == -1) {
		cout << "error on wiring pi setup" << endl;
	} else {
		cout << "wiring pi setup OK" << endl;
	}

	cout << "start sonar" << endl;

	sonar.init(TRIGGER_M, ECHO_M);
}

int get_distance() {
	return sonar.distance(30000);
}

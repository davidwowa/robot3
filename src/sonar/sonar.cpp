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

Sonar sonar_m;
Sonar sonar_r;
Sonar sonar_l;
Sonar sonar_b;

void init_sonar() {

	if (wiringPiSetup() == -1) {
		cout << "error on wiring pi setup" << endl;
	} else {
		cout << "wiring pi setup OK" << endl;
	}

	cout << "start sonars" << endl;

	sonar_m.init(TRIGGER_M, ECHO_M);

	sonar_r.init(TRIGGER_R, ECHO_R);

	sonar_l.init(TRIGGER_L, ECHO_L);

	sonar_b.init(TRIGGER_B, ECHO_B);
}

int get_distance_m() {
	return sonar_m.distance(30000);
}
int get_distance_r() {
	return sonar_r.distance(30000);
}
int get_distance_l() {
	return sonar_l.distance(30000);
}
int get_distance_b() {
	return sonar_b.distance(30000);;
}

int get_minimal_distance(int m, int r, int l) {
	int result = m;
	if (r < result) {
		result = r;
	}
	if (l < result) {
		result = l;
	}
	cout << "minimal distance is " << result << endl;
	return result;
}

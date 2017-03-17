/*
 * sonar_test.cpp
 *
 *  Created on: 17.03.2017
 *      Author: Wladimir David Zakrevskyy
 */
#include <iostream>

#include "../../sonar/sonar.h"

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"

using namespace std;

int main(void) {
	cout << "display show" << endl;
	init_sonar();

	int i = 100;
	int counter = 0;

	while (counter <= i) {

		int distance_m = get_distance_m();
		int distance_r = get_distance_r();
		int distance_l = get_distance_l();
		int distance_b = get_distance_b();

		cout << "Distance on middle sensor is " << distance_m << " cm." << endl;
		cout << "Distance on right  sensor is " << distance_r << " cm." << endl;
		cout << "Distance on left   sensor is " << distance_l << " cm." << endl;
		cout << "Distance on back   sensor is " << distance_b << " cm." << endl;
		cout << "---" << endl;
		counter++;
	}
	return -1;
}

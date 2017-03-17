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

		int distance_m = get_distance();

		cout << "Distance on middle sensor is " << distance_m << " cm." << endl;
		cout << "---" << endl;
		counter++;
	}
	return -1;
}

//============================================================================
// Name        : test_motors.cpp
// Author      : Zakrevskyy Wladimir David
// Version     :
// Copyright   :
// Description :
//============================================================================

#include "iostream"

#include "../../drive/drive.h"

#include "../../sonar/sonar.h"

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../../lib/WiringPi/wiringPi/softPwm.h"

using namespace std;

int main(void) {
	init_drive();

	cout << "drive forward" << endl;
	drive_forward();
	delay(1000);
	cout << "drive backward" << endl;
	drive_backward();
	delay(1000);
	cout << "drive right" << endl;
	turn_right();
	delay(1000);
	cout << "drive left" << endl;
	turn_left();
	delay(1000);

	// acceleration forward
	cout << "acceleration forward" << endl;
	for (int var = 0; var < 200; ++var) {
		cout << "set speed to " << var << endl;
		drive_forward(var);
		delay(10);
	}
	// acceleration backward
	cout << "acceleration backward" << endl;
	for (int var = 0; var < 200; ++var) {
		cout << "set speed to " << var << endl;
		drive_backward(var);
		delay(10);
	}

	cout << "stop" << endl;
	drive_backward(0);

	return -1;
}
//============================================================================
// Name        : drive_backward.cpp
// Author      : Zakrevskyy Wladimir David
// Version     : v.0.1
// Copyright   :
// Description :
//============================================================================

#include "iostream"

#include "../../drive/drive.h"
#include "../../sonar/sonar.h"
#include "../../servo/servo.h"

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../../lib/WiringPi/wiringPi/softPwm.h"

using namespace std;

int main(void) {

	init_drive();

	cout << "drive backward" << endl;
	drive_backward(0);

	return 1;
}

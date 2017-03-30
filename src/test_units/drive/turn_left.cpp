//============================================================================
// Name        : drive_left.cpp
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

	system("sudo kill $(pidof python)");
	system(
			"python /home/pi/Pimoroni/scrollphat/examples/scroll-text-forever.py LEFT &");

	cout << "turn left" << endl;
	turn_left(0);

	return 1;
}

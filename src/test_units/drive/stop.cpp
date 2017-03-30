//============================================================================
// Name        : drive_stop.cpp
// Author      : Zakrevskyy Wladimir David
// Version     : v.0.1
// Copyright   :
// Description :
//============================================================================

#include "../../drive/drive.h"
#include "../../sonar/sonar.h"
#include "../../servo/servo.h"

#include "../../../lib/WiringPi/wiringPi/wiringPi.h"
#include "../../../lib/WiringPi/wiringPi/softPwm.h"

int main(void) {

	init_drive();

	drive_backward(500);

	return 1;
}

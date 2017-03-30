/*
 * gpio_servo.h
 *
 *  Created on: 30.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#ifndef SERVO_GPIO_SERVO_H_
#define SERVO_GPIO_SERVO_H_

// servo pins
extern const int SERVO_1 = 2;
extern const int SERVO_2 = 3;

// pwm
extern const int SERVO_PWM_MAX = 200;
extern const int SERVO_PWM_MIN = 0;

// delay
extern const int SERVO_DELAY = 15;

// directions
extern const int SERVO_LEFT = 14;
extern const int SERVO_RIGHT = 8;
extern const int SERVO_CENTER_X = 11;
extern const int SERVO_UP = 0;
extern const int SERVO_DOWN = 13;
extern const int SERVO_CENTER_Y = 9;

#endif /* SERVO_GPIO_SERVO_H_ */

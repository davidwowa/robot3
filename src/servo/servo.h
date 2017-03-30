/*
 * servo.h
 *
 *  Created on: 30.03.2017
 *      Author: Wladimir David Zakrevskyys
 */

#ifndef SERVO_SERVO_H_
#define SERVO_SERVO_H_

extern void init_servo(void);

extern void init_wiringPi(void);
extern void init_PWM(void);

extern void move_left(void);
extern void move_right(void);
extern void move_center_x(void);
extern void move_up(void);
extern void move_down(void);
extern void move_center_y(void);

#endif /* SERVO_SERVO_H_ */

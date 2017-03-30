/*
 * drive.h
 *
 *  Created on: 17.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#ifndef DRIVE_H_
#define DRIVE_H_

extern void init_drive(void);

extern void drive_backward(void);
extern void drive_forward(void);
extern void turn_left(void);
extern void turn_right(void);

extern void drive_backward(int pwm);
extern void drive_forward(int pwm);
extern void turn_left(int pwm);
extern void turn_right(int pwm);

extern void drive_backward(int pin, int pwm);
extern void drive_forward(int pin, int pwm);
extern void turn_left(int pin, int pwm);
extern void turn_right(int pin, int pwm);

extern void stop_motors(void);

extern void init_drive_wiringPi(void);
extern void init_drive_PWM(void);

extern void set_working_pins_to_low(void);

#endif /* DRIVE_H_ */

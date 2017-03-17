/*
 * sonar.h
 *
 *  Created on: 17.03.2017
 *      Author: Wladimir David Zakrevskyy
 */

#ifndef SONAR_H_
#define SONAR_H_

extern void init_sonar(void);
extern int get_distance_m();
extern int get_distance_r();
extern int get_distance_l();
extern int get_distance_b();

extern int get_minimal_distance(int m, int r, int l);

#endif /* SONAR_H_ */

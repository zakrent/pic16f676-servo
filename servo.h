/* 
 * File:   servo.h
 * Author: zakrent
 *
 * Created on September 29, 2018, 3:25 PM
 */

#ifndef SERVO_H
#define	SERVO_H

#include <xc.h>
#include <stdint.h>

#define MAX_SERVOS 4

void servo_init();
void servo_interrupt();
uint8_t servo_new(unsigned char* port,unsigned char* tris, char mask);
void servo_set(uint8_t id, uint8_t value);

#endif	/* SERVO_H */


/* 
 * File:   joystick.h
 * Author: zakrent
 *
 * Created on September 29, 2018, 11:22 PM
 */

#ifndef JOYSTICK_H
#define	JOYSTICK_H

#include <xc.h>
#include <stdint.h>

void joystick_init();
uint8_t joystick_get_x();
uint8_t joystick_get_y();

#endif	/* JOYSTICK_H */


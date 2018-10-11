/* 
 * File:   timer.h
 * Author: zakrent
 *
 * Created on October 5, 2018, 6:06 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#include <xc.h>
#include <stdint.h>

void timer_init();
void timer_int_period(unsigned int time_us);
void timer_handle_int();
void timer_int_enable();
void timer_int_disable();

#endif	/* TIMER_H */


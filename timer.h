/* 
 * File:   timer.h
 * Author: zakrent
 *
 * Created on October 5, 2018, 6:06 PM
 */

#ifndef TIMER_H
#define	TIMER_H

void timer_init();
void timer_int_period(int time_us);
void timer_int_enable();
void timer_int_disable();

#endif	/* TIMER_H */


/*
 * File:   main.c
 * Author: zakrent
 *
 * Created on September 22, 2018, 2:04 PM
 */

//#include <xc.h>
//#include <stdlib.h>
//#include "system.h"
//#include "timer.h"
//#include "servo.h"
//#include "joystick.h"

/*void __interrupt() isr(){
    GIE = 0;
    if(T0IF == 1){
        T0IF = 0;
        timer_handle_int();
        servo_interrupt();
    }
    
    GIE = 1;
}

void init(){
    OPTION_REG = 0b01010111;
    INTCON = 0b10000000;
    ANSEL = 0x00;
    joystick_init();
    timer_init();
    //servo_init();
    //servo_new(&PORTC, &TRISC, 1 << 3);
    //servo_new(&PORTC, &TRISC, 1 << 4);
}

void main(void) {
    init();
    while(1){
        //servo_set(0, joystick_get_y());
        //servo_set(1, joystick_get_x());
        __delay_ms(10);
    }
    return;
}*/

void main(void) {
    while(1);
    return;
}
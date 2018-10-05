#include "timer.h"

void timer_init(){
    T0CS = 0;
    PSA = 0;
    PS0 = 0;
    PS1 = 0;
    PS2 = 0;
    T0IE = 0;
    TMR0 = 0;
}

void timer_int_period(int time_us){
    
}

void timer_int_enable(){
    T0IE = 1;
}

void timer_int_disable(){
    T0IE = 0;
}

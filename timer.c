#include "timer.h"
#include "system.h"

static const unsigned int BASE_CLK_PERIOD = 10^6/(_XTAL_FREQ/8);
uint8_t timer_preload = 0;

void timer_init(){
    T0CS = 0;
    PSA  = 0;
    PS0  = 0;
    PS1  = 0;
    PS2  = 0;
    T0IE = 0;
    TMR0 = 0;
}

void timer_int_period(unsigned int time_us){
    uint8_t prescaler = 0;
    int current_clk_period = BASE_CLK_PERIOD;
    while(time_us/current_clk_period >= 0xff){
        prescaler++;
        current_clk_period *= 2;
        if(prescaler & 0b1000){
            //Error
            return;
        }
    }
    PS0 = prescaler & 0b001;
    PS1 = prescaler & 0b010;
    PS2 = prescaler & 0b100;
    timer_preload = 0xff - time_us/current_clk_period;
    TMR0 = timer_preload;
}

void timer_handle_int(){
    TMR0 = timer_preload;
}

void timer_int_enable(){
    T0IE = 1;
}

void timer_int_disable(){
    T0IE = 0;
}

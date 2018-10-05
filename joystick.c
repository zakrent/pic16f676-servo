#include "joystick.h"
#include "system.h"

uint8_t y_offset = 0;
uint8_t x_offset = 0;

void joystick_init(){
    ADCON0 = 0b00010001;
    ADCON1 = 0b00010000;
    ANSEL  = 0b00110000 ;
    x_offset = joystick_get_x();
    y_offset = joystick_get_y();
}

uint8_t adc_read(){
    GO_DONE = 1;
    while(GO_DONE == 1){}
    return ADRESH;
}

uint8_t joystick_get_x(){
    CHS0 = 0;
    CHS1 = 0;
    CHS2 = 1;
    return adc_read();
}

uint8_t joystick_get_y(){
    CHS0 = 1;
    CHS1 = 0;
    CHS2 = 1;
    return adc_read();
}

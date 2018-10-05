#include "servo.h"
#include "lcd.h"
#include <stdint.h>

enum state {
    PWM_ON1,
    PWM_ON2,
    PWM_OFF
};
enum state current_state = PWM_OFF;

struct servo {
    char* port;
    char mask;
    uint8_t value;
};

uint8_t current_servo = 0;
uint8_t n_servos = 0;
struct servo servos[MAX_SERVOS];

void servo_init(){
    T0IE = 1;
    PSA = 0;
    PS2 = 0;
    PS1 = 0;
    PS0 = 1;
    TMR0 = 0;       
}

void servo_interrupt(){
    switch(current_state){
        case PWM_OFF:
            current_servo++;
            if(current_servo == n_servos){
                current_servo = 0xff;
                PS2 = 1;
                PS1 = 1;
                PS0 = 0;
                TMR0 = 111+n_servos*8;          
            }
            else{
                *(servos[current_servo].port) |= servos[current_servo].mask;
                current_state = PWM_ON1;
                PS2 = 0;
                PS1 = 0;
                PS0 = 1;
                TMR0 = 42;             
            }
            break;
        case PWM_ON1:
            current_state = PWM_ON2;
            TMR0 = servos[current_servo].value;             
            break;
        case PWM_ON2:
            *(servos[current_servo].port) &= 0xff ^ servos[current_servo].mask;
            current_state = PWM_OFF;
            TMR0 = 0xff-servos[current_servo].value;             
            break;
    }
}
uint8_t servo_new(char* port, char* tris, char mask){
    *tris &= 0xff ^ mask;
    struct servo new_servo = {port, mask, 0xaa};
    servos[n_servos] = new_servo;
    n_servos++;
    return n_servos-1;
}
void servo_set(uint8_t id, uint8_t value){
    servos[id].value = value;
}

#include "servo.h"
#include "timer.h"
#include <stdint.h>

enum state {
    PWM_ON1,
    PWM_ON2,
    PWM_OFF
};
enum state current_state = PWM_OFF;

struct servo {
    unsigned char* port;
    char mask;
    uint8_t value;
};

uint8_t current_servo = 0;
uint8_t n_servos = 0;
struct servo servos[MAX_SERVOS];

void servo_init(){
    timer_int_enable();
}

void servo_interrupt(){
    switch(current_state){
        case PWM_OFF:
            current_servo++;
            if(current_servo == n_servos){
                current_servo = 0xff;
                timer_int_period(50000-(2000*n_servos));
            }
            else{
                *(servos[current_servo].port) |= servos[current_servo].mask;
                current_state = PWM_ON1;
                timer_int_period(1000);      
            }
            break;
        case PWM_ON1:
            current_state = PWM_ON2;
            timer_int_period(servos[current_servo].value*4);
            break;
        case PWM_ON2:
            *(servos[current_servo].port) &= 0xff ^ servos[current_servo].mask;
            timer_int_period(1000-servos[current_servo].value*4);
            break;
    }
}
uint8_t servo_new(unsigned char* port,unsigned char* tris,char mask){
    *tris &= 0xff ^ mask;
    struct servo new_servo = {port, mask, 0xaa};
    servos[n_servos] = new_servo;
    n_servos++;
    return n_servos-1;
}
void servo_set(uint8_t id, uint8_t value){
    servos[id].value = value;
}

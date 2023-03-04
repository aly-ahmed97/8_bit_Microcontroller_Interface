/*
 * File:   Application.c
 * Author: Aly Ahmed
 *
 * Created on February 16, 2023, 4:11 PM
 */
#include "ECU_LAYER/LED/ECU_LED.h"
#include "ECU_LAYER/PUSH_BUTTON/ECU_PUSH_BUTTON.h"
#include "ECU_LAYER/RELAY/ECU_RELAY.h"
led_t Led1 = {
    .port = PORTC_INDEX,
    .pin  = GPIO_PIN0,
    .led_status = GPIO_LOW
};
led_t Led2 = {
    .port = PORTC_INDEX,
    .pin  = GPIO_PIN1,
    .led_status = GPIO_LOW
};
led_t Led3 = {
    .port = PORTC_INDEX,
    .pin  = GPIO_PIN2,
    .led_status = GPIO_LOW
};
led_t Led4 = {
    .port = PORTC_INDEX,
    .pin  = GPIO_PIN3,
    .led_status = GPIO_LOW
};
int main() {
    Std_ReturnType ret = E_NOT_OK ;
    ret = led_init(&Led1);
    ret = led_init(&Led2);
    ret = led_init(&Led3);
    ret = led_init(&Led4);
    while(1)
    {
        ret = led_turn_on(&Led1);
        ret = led_turn_off(&Led2);
        ret = led_turn_on(&Led3);
        ret = led_turn_off(&Led4);
        __delay_ms(500);
        ret = led_turn_off(&Led1);
        ret = led_turn_on(&Led2);
        ret = led_turn_off(&Led3);
        ret = led_turn_on(&Led4);
        __delay_ms(500);
        
    }
    return (EXIT_SUCCESS);
}   

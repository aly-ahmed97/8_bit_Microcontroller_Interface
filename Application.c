/*
 * File:   Application.c
 * Author: Aly Ahmed
 *
 * Created on February 16, 2023, 4:11 PM
 */
#include "ECU_LAYER/LED/ECU_LED.h"


int main() {
    Std_ReturnType ret = E_NOT_OK ;
    ret = gpio_port_direction_init(PORTC_INDEX,0);
    ret = gpio_port_write_logic(PORTC_INDEX,0x55);
    while(1)
    {
        ret = gpio_port_toggle_logic(PORTC_INDEX);
        __delay_ms(500);
    }
    return (EXIT_SUCCESS);
}   

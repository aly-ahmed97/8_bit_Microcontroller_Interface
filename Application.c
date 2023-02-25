/*
 * File:   Application.c
 * Author: Aly Ahmed
 *
 * Created on February 16, 2023, 4:11 PM
 */
#include "ECU_LAYER/LED/ECU_LED.h"

pinConfig_t led_1 = {
  .Port = PORTC_INDEX,
  .Pin_Number  = GPIO_PIN0,
  .Direction = GPIO_OUTPUT,
  .Logic = GPIO_HIGH
};

int main() {
    
    return (EXIT_SUCCESS);
}   

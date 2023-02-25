/* 
 * File:   HAL_GPIO.c
 * Author: Aly Ahmed
 *
 * Created on February 16, 2023, 4:19 PM
 */

#include "HAL_GPIO.h"

volatile uint8_t *tris_registers[] =  {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE}; // Reference to data direction control registers 
volatile uint8_t *port_registers[] =  {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE}; // Reference to port status registers
volatile uint8_t *lat_registers[] =   {&LATA,  &LATB,  &LATC,  &LATD,  &LATE};  // Reference to data latch registers

Std_ReturnType gpio_pin_direction_init(const pinConfig_t *_pin_config){
    
}
Std_ReturnType gpio_pin_get_direction_status(const pinConfig_t *_pin_config,direction_t *direction_status){
    
}
Std_ReturnType gpio_pin_write_logic(const pinConfig_t *_pin_config,logic_t logic){
    
}
Std_ReturnType gpio_pin_read_logic(const pinConfig_t *_pin_config,logic_t *logic){
    
}
Std_ReturnType gpio_pin_toggle_logic(const pinConfig_t *_pin_config){
    
}

Std_ReturnType gpio_port_direction_init(portIndex_t port, uint8_t direction){
    
}
Std_ReturnType gpio_port_get_direction_status(portIndex_t port,uint8_t *direction_status){
    
}
Std_ReturnType gpio_port_write_logic(portIndex_t port,uint8_t logic){
    
}
Std_ReturnType gpio_port_read_logic(portIndex_t port,uint8_t *logic){
    
}
Std_ReturnType gpio_port_toggle_logic(portIndex_t port){
    
}
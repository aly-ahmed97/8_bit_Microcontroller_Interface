/* 
 * File:   ECU_LED.c
 * Author: Aly Ahmed
 *
 * Created on February 16, 2023, 5:24 PM
 */
#include "ECU_LED.h"

/**
 * @brief initialize the required pin to be OUTPUT and sets its state
 * @param led : pointer to led module configuration
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if LED_CONTROL == LED_ENABLE
Std_ReturnType led_init(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led)
    {
       ret = E_NOT_OK ; 
    }
    else if(led->pin > PORT_PIN_MAX_NUMBER-1 || led->port >= PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        pinConfig_t Pin_obj = {
        .Port       = led->port      ,
        .Pin_Number = led->pin       ,
        .Direction  = GPIO_OUTPUT    ,
        .Logic      = led->led_status
        };
        ret = gpio_pin_direction_init(&Pin_obj);
    }
    return ret ;
}
#endif
/**
 * @brief TURN the led ON
 * @param led : pointer to led module configuration
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if LED_CONTROL == LED_ENABLE
Std_ReturnType led_turn_on(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led)
    {
       ret = E_NOT_OK ; 
    }
    else if(led->pin > PORT_PIN_MAX_NUMBER-1 || led->port >= PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
         pinConfig_t Pin_obj = {
        .Port       = led->port      ,
        .Pin_Number = led->pin       ,
        .Direction  = GPIO_OUTPUT    ,
        .Logic      = led->led_status
        };
        ret = gpio_pin_write_logic(&Pin_obj,GPIO_HIGH);
    }
    return ret ;
}
#endif
/**
 * @brief TURN the led OFF
 * @param led : pointer to led module configuration
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if LED_CONTROL == LED_ENABLE
Std_ReturnType led_turn_off(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led)
    {
       ret = E_NOT_OK ; 
    }
    else if(led->pin > PORT_PIN_MAX_NUMBER-1 || led->port >= PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        pinConfig_t Pin_obj = {
        .Port       = led->port      ,
        .Pin_Number = led->pin       ,
        .Direction  = GPIO_OUTPUT    ,
        .Logic      = led->led_status
        };
        ret = gpio_pin_write_logic(&Pin_obj,GPIO_LOW);   
    }
    return ret ; 
}
#endif
/**
 * @brief TOGGLE the led state (on to off ) or (off to on)
 * @param led : pointer to led module configuration
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if LED_CONTROL == LED_ENABLE
Std_ReturnType led_toggle_state(const led_t *led){
    Std_ReturnType ret = E_OK ;
    if(NULL == led)
    {
       ret = E_NOT_OK ; 
    }
    else if(led->pin > PORT_PIN_MAX_NUMBER-1 || led->port >= PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        pinConfig_t Pin_obj = {
        .Port       = led->port      ,
        .Pin_Number = led->pin       ,
        .Direction  = GPIO_OUTPUT    ,
        .Logic      = led->led_status
        };
        ret = gpio_pin_toggle_logic(&Pin_obj);
    }
    return ret ;
}
#endif
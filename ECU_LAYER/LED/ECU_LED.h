/* 
 * File:   ECU_LED.h
 * Author: Aly Ahmed
 *
 * Created on February 16, 2023, 5:24 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


/* Includes Section : */

#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"
#include "ECU_LED_CONFIG.h"

/* Macro Declarations Section : */

#define LED_CONTROL LED_ENABLE

/* Macro Functions Declarations Section : */

/* Data Types Section*/

typedef enum{
    LED_OFF =0,
    LED_ON
}led_status;

typedef struct{
    uint8_t port        :3 ;
    uint8_t pin         :3 ;
    uint8_t led_status  :1 ;
    uint8_t reserved    :1 ; // not used
}led_t;

/* Functions Declarations Section */

Std_ReturnType led_init(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_toggle_state(const led_t *led);

#endif	/* ECU_LED_H */


/* 
 * File:   ECU_PUSH_BUTTON.h
 * Author: Aly Ahmed
 *
 * Created on February 25, 2023, 9:54 PM
 */

#ifndef ECU_PUSH_BUTTON_H
#define	ECU_PUSH_BUTTON_H

/* Includes Section : */

#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"
#include "ECU_PUSH_BUTTON_CONFIG.h"

/* Macro Declarations Section : */

#define PUSH_BUTTON_CONTROL PUSH_BUTTON_ENABLE

/* Macro Functions Declarations Section : */

/* Data Types Section*/

typedef enum{
    BUTTON_PRESSED = 0,
    BUTTON_RELEASED
}button_state_t;
typedef enum{
   BUTTON_ACTIVE_HIGH = 0,
   BUTTON_ACTIVE_LOW
}button_active_t;
typedef struct{
    pinConfig_t button_pin ;
    button_state_t button_state;
    button_active_t button_active_logic;
}button_t;
/* Functions Declarations Section */

Std_ReturnType button_init(const button_t *btn);
Std_ReturnType button_read_state(const button_t *btn,button_state_t *state);

#endif	/* ECU_PUSH_BUTTON_H */


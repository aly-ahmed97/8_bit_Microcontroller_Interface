/* 
 * File:   RELAY.h
 * Author: Aly Ahmed
 *
 * Created on March 4, 2023, 2:38 PM
 */

#ifndef RELAY_H

#define	RELAY_H
/* Includes Section : */

#include "ECU_RELAY_CONFIG.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"

/* Macro Declarations Section : */

#define RELAY_CONTROL RELAY_ENABLE

#define RELAY_ON_STATUS 0x01U
#define RELAY_OFF_STATUS 0x00U 

/* Macro Functions Declarations Section : */

/* Data Types Section*/

typedef struct {
    uint8_t Relay_Port    :3 ;
    uint8_t Relay_Pin     :3 ;
    uint8_t Relay_statues :1 ;
    uint8_t Reserved      :1 ;
}Relay_t;

/* Functions Declarations Section */

Std_ReturnType Relay_init   (const Relay_t *Relay);
Std_ReturnType Relay_TurnOn (const Relay_t *Relay);
Std_ReturnType Relay_TurnOff(const Relay_t *Relay);

#endif	/* RELAY_H */  


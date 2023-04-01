/* 
 * File:   mcal_Interrupt_config.h
 * Author: Aly Ahmed
 *
 * Created on March 31, 2023, 2:11 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* Includes Section : */

#include "../../../pic/include/proc/pic18f4620.h"
#include "../MCAL_STD_TYPES.h"
#include "../GPIO/HAL_GPIO.h"
#include "mcal_Interrupt_Gen_CFG.h"

/* Macro Declarations Section : */

#define INTURRUPT_DISABLE           0x00
#define INTERUPPT_ENABLE            0x01

#define INTURRUPT_NOT_OCCUR         0x00
#define INTURRUPT_OCCUR             0x01

/* Macro Functions Declarations Section : */
#if INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_ENABLE

    #define INTURRUPT_GlobalInterruptPriorityDisable() (RCONbits.IPEN  =   0x00)
    #define INTURRUPT_GlobalInterruptPriorityEnable()  (RCONbits.IPEN  =   0x01)

    #define INTURRUPT_GlobalInterruptHighDisable()      (INTCONbits.GIEH  = 0x00)
    #define INTURRUPT_GlobalInterruptHighEnable()       (INTCONbits.GIEH  = 0x01)

    #define INTURRUPT_GlobalInterruptLowDisable()       (INTCONbits.GIEL  = 0x00)
    #define INTURRUPT_GlobalInterruptLowEnable()        (INTCONbits.GIEL  = 0x01)

#elif INTURRUPT_PERIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_DISABLE

    #define INTURRUPT_GlobalInterruptDisable()          (INTCONbits.GIE  =  0x00)
    #define INTURRUPT_GlobalInterruptEnable()           (INTCONbits.GIE  =  0x01)

    #define INTURRUPT_PeripheralInterruptDisable()      (INTCONbits.PEIE  = 0x00)
    #define INTURRUPT_PeripheralInterruptEnable()       (INTCONbits.PEIE  = 0x01)

#endif

/* Data Types Section*/
typedef enum{
    LOW_Priority = 0,
    HIGH_Priority
}Interrupt_priority_cfg;
/* Functions Declarations Section */

#endif	/* MCAL_INTERRUPT_CONFIG_H */


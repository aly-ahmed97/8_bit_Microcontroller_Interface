/* 
 * File:   ECU_KEYBAD.h
 * Author: Aly Ahmed
 *
 * Created on March 11, 2023, 5:13 PM
 */

#ifndef ECU_KEYBAD_H
#define	ECU_KEYBAD_H
/* Includes Section : */

#include "ECU_KEYBAD_CONFIG.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"

/* Macro Declarations Section : */

#define KEYBAD_CONTROL KEYBAD_ENABLE

#define KEYBAD_ROWS     4
#define KEYBAD_COLUMNS  4

/* Macro Functions Declarations Section : */

/* Data Types Section*/

typedef struct{
    pinConfig_t Rows[KEYBAD_ROWS];
    pinConfig_t Columns[KEYBAD_COLUMNS];
}Keybad_t;

const uint8_t button_Values[KEYBAD_ROWS][KEYBAD_COLUMNS] = 
{
        { '7' , '8' , '9' , '/' } ,
        { '4' , '5' , '6' , '*' } ,
        { '1' , '2' , '3' , '-' } ,
        { '#' , '0' , '=' , '+' } 
};

/* Functions Declarations Section */

Std_ReturnType keybad_init(const Keybad_t *Keybad);
Std_ReturnType keybad_get_value(const Keybad_t *Keybad,uint8_t *value);

#endif	/* ECU_KEYBAD_H */


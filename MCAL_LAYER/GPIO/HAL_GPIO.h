/* 
 * File:   HAL_GPIO.h
 * Author: Aly Ahmed
 *
 * Created on February 16, 2023, 4:19 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Includes Section : */

#include "../../../pic/include/proc/pic18f4620.h"
#include "../MCAL_STD_TYPES.h"
#include "../DEVICE_CONFIG.h"

/* Macro Declarations Section : */

#define BIT_MASK (uint8_t)1

/* Macro Functions Declarations Section : */

#define HWREG_8(_x)               (*(volatile uint8_t *)(_x))

#define SET_BIT(REG,BIT_POSN)     (REG |= (BIT_MASK<<BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)   (REG &= ~(BIT_MASK<<BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)  (REG ^= (BIT_MASK<<BIT_POSN))

#define READ_BIT(REG,BIT_POSN)    ((REG >> BIT_POSN) & BIT_MASK)

/* Data Types Section*/

typedef enum {
    GPIO_LOW = 0,
    GPIO_HIGH
}logic_t;
typedef enum{
    GPIO_OUTPUT = 0,
    GPIO_INPUT
}direction_t;
typedef enum{
    GPIO_PIN0 = 0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
            
}pinIndex_t;
typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX,
}portIndex_t;

typedef struct{
    uint8_t Port       : 3 ;
    uint8_t Pin_Number : 3 ;
    uint8_t Direction  : 1 ;
    uint8_t Logic      : 1 ;
}pinConfig_t;
/* Functions Declarations Section */

Std_ReturnType gpio_pin_direction_init(const pinConfig_t *_pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pinConfig_t *_pin_config,direction_t *direction_status);
Std_ReturnType gpio_pin_write_logic(const pinConfig_t *_pin_config,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pinConfig_t *_pin_config,logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pinConfig_t *_pin_config);

Std_ReturnType gpio_port_direction_init(portIndex_t port, uint8_t direction);
Std_ReturnType gpio_port_get_direction_status(portIndex_t port,uint8_t *direction_status);
Std_ReturnType gpio_port_write_logic(portIndex_t port,uint8_t logic);
Std_ReturnType gpio_port_read_logic(portIndex_t port,uint8_t *logic);
Std_ReturnType gpio_port_toggle_logic(portIndex_t port);

#endif	/* HAL_GPIO_H */


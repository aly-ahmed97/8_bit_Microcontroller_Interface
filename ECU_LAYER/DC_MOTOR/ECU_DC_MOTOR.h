/* 
 * File:   ECU_DC_MOTOR.h
 * Author: Aly Ahmed
 *
 * Created on March 4, 2023, 7:51 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H
 

/* Includes Section : */

#include "ECU_DC_MOTOR_CONFIG.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"

/* Macro Declarations Section : */

#define DC_MOTOR_CONTROL DC_MOTOR_ENABLE

/* Macro Functions Declarations Section : */

#define DC_MOTOR_ON_STATUS 0x01U
#define DC_MOTOR_OFF_STATUS 0x00U

#define DC_MOTOR_PIN1 0x00U
#define DC_MOTOR_PIN2 0x01U

/* Data Types Section*/

typedef struct{
    uint8_t Pin_Port    :3 ;
    uint8_t Pin_Pin     :3 ;
    uint8_t Pin_statues :1 ;
    uint8_t Reserved      :1 ;   
}Dc_Motor_Pin_t;

typedef struct{
   Dc_Motor_Pin_t dc_motor_pin[2];
}Dc_Motor_t;
/* Functions Declarations Section */

Std_ReturnType Dc_Motor_INIT(const Dc_Motor_t * dc_motor);
Std_ReturnType Dc_Motor_Turn_Right(const Dc_Motor_t * dc_motor);
Std_ReturnType Dc_Motor_Turn_Left(const Dc_Motor_t * dc_motor);
Std_ReturnType Dc_Motor_Stop(const Dc_Motor_t * dc_motor);

#endif	/* ECU_DC_MOTOR_H */


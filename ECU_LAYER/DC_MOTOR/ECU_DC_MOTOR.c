 
#include "ECU_DC_MOTOR.h"

static  pinConfig_t pin1 ;
static  pinConfig_t pin2 ;

/**
 * @brief initialize the required pins to be OUTPUTS
 * @param dc_motor : pointer to dc motor configurations 
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has is sue to complete execution
 */
#if DC_MOTOR_CONTROL == DC_MOTOR_ENABLE
Std_ReturnType Dc_Motor_INIT(const Dc_Motor_t * dc_motor){
    Std_ReturnType ret = E_OK ;
    if(NULL == dc_motor)
    {
        ret = E_NOT_OK ;
    }
    else
    {
            pin1.Port       = dc_motor->dc_motor_pin[DC_MOTOR_PIN1].Pin_Port   ;
            pin1.Pin_Number = dc_motor->dc_motor_pin[DC_MOTOR_PIN1].Pin_Pin    ;
            pin1.Direction  = GPIO_OUTPUT                                      ;
            pin1.Logic      = dc_motor->dc_motor_pin[DC_MOTOR_PIN1].Pin_statues;
            
            pin2.Port       = dc_motor->dc_motor_pin[DC_MOTOR_PIN2].Pin_Port   ;
            pin2.Pin_Number = dc_motor->dc_motor_pin[DC_MOTOR_PIN2].Pin_Pin    ;
            pin2.Direction  = GPIO_OUTPUT                                      ;
            pin2.Logic      = dc_motor->dc_motor_pin[DC_MOTOR_PIN2].Pin_statues;
            
        ret  = gpio_pin_direction_init(&pin1);
        ret  = gpio_pin_direction_init(&pin2);
    }
    return ret ; 
}
#endif
/**
 * @brief turns the dc motor to right direction
 * @param dc_motor : pointer to dc motor configurations 
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has is sue to complete execution
 */
#if DC_MOTOR_CONTROL == DC_MOTOR_ENABLE
Std_ReturnType Dc_Motor_Turn_Right(const Dc_Motor_t * dc_motor){
    Std_ReturnType ret = E_OK ;
    if(NULL == dc_motor)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret  = gpio_pin_write_logic(&pin1,GPIO_HIGH);
        ret  = gpio_pin_write_logic(&pin2,GPIO_LOW);
    }
    return ret ;  
}
#endif
/**
 * @brief turns the dc motor to left direction
 * @param dc_motor : pointer to dc motor configurations 
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has is sue to complete execution
 */
#if DC_MOTOR_CONTROL == DC_MOTOR_ENABLE
Std_ReturnType Dc_Motor_Turn_Left(const Dc_Motor_t * dc_motor){
    Std_ReturnType ret = E_OK ;
    if(NULL == dc_motor)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret  = gpio_pin_write_logic(&pin1,GPIO_LOW);
        ret  = gpio_pin_write_logic(&pin2,GPIO_HIGH);
    }
    return ret ; 
}
#endif
/**
 * @brief stops the dc motor
 * @param dc_motor : pointer to dc motor configurations 
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has is sue to complete execution
 */
#if DC_MOTOR_CONTROL == DC_MOTOR_ENABLE
Std_ReturnType Dc_Motor_Stop(const Dc_Motor_t * dc_motor){
    Std_ReturnType ret = E_OK ;
    if(NULL == dc_motor)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret  = gpio_pin_write_logic(&pin1,GPIO_LOW);
        ret  = gpio_pin_write_logic(&pin2,GPIO_LOW);
    }
    return ret ; 
}
#endif

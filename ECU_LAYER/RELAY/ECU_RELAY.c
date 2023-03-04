

#include "ECU_RELAY.h"
/**
 * @brief initialize the required pin to be OUTPUT
 * @param Relay : pointer to relay configurations 
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has is sue to complete execution
 */
#if RELAY_CONTROL == RELAY_ENABLE
Std_ReturnType Relay_init   (const Relay_t *Relay){
    Std_ReturnType ret = E_OK ;
    if(NULL == Relay)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        pinConfig_t rel = {
            .Port       = Relay->Relay_Port ,
            .Pin_Number = Relay->Relay_Pin  ,
            .Direction  = GPIO_OUTPUT        ,
            .Logic      = GPIO_LOW
        };
        ret  = gpio_pin_direction_init(&rel);
    }
    return ret ; 
}
#endif
/**
 * @brief turns the relay on
 * @param Relay : pointer to relay configurations 
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if RELAY_CONTROL == RELAY_ENABLE
Std_ReturnType Relay_TurnOn (const Relay_t *Relay){
     Std_ReturnType ret = E_OK ;
    if(NULL == Relay)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        pinConfig_t rel = {
            .Port       = Relay->Relay_Port ,
            .Pin_Number = Relay->Relay_Pin  ,
            .Direction  = GPIO_OUTPUT        ,
            .Logic      = GPIO_LOW
        };
        ret  = gpio_pin_write_logic(&rel,GPIO_HIGH);
    }
    return ret ;
}
#endif
/**
 * @brief turns the relay on
 * @param Relay : pointer to relay configurations 
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if RELAY_CONTROL == RELAY_ENABLE
Std_ReturnType Relay_TurnOff(const Relay_t *Relay){
     Std_ReturnType ret = E_OK ;
    if(NULL == Relay)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        pinConfig_t rel = {
            .Port       = Relay->Relay_Port ,
            .Pin_Number = Relay->Relay_Pin  ,
            .Direction  = GPIO_OUTPUT        ,
            .Logic      = GPIO_LOW
        };
        ret  = gpio_pin_write_logic(&rel,GPIO_LOW);
    }
    return ret ;
}
#endif
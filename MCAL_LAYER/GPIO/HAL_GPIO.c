/* 
 * File:   HAL_GPIO.c
 * Author: Aly Ahmed
 *
 * Created on February 16, 2023, 4:19 PM
 */

#include "HAL_GPIO.h"

volatile uint8_t *tris_registers[] =  {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE}; // Reference to data direction control registers 
volatile uint8_t *port_registers[] =  {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE}; // Reference to port status registers
volatile uint8_t *lat_registers[] =   {&LATA,  &LATB,  &LATC,  &LATD,  &LATE};  // Reference to data latch registers

/**
 * @brief initialize direction of a specific pin  @ref direction_t
 * @param _pin_config : pointer to the configuration @ref pinConfig_t
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_init(const pinConfig_t *_pin_config){
    Std_ReturnType ret = E_OK ;
    if(NULL == _pin_config)
    {
       ret = E_NOT_OK ; 
    }
    else if(_pin_config->Pin_Number > PORT_PIN_MAX_NUMBER-1 || _pin_config->Port >= PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(_pin_config->Direction)
        {
            case (GPIO_OUTPUT) :
                CLEAR_BIT( *tris_registers[_pin_config->Port] , _pin_config->Pin_Number);
                break;
            case (GPIO_INPUT)  :
                SET_BIT( *tris_registers[_pin_config->Port] , _pin_config->Pin_Number);
                break;
            default            :
                ret = E_NOT_OK ;
        }
    }
    return ret ;
}
#endif
/**
 * @brief get direction of a specific pin  @ref direction_t
 * @param _pin_config : pointer to the configuration @ref pinConfig_t
 * @param direction_status
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pinConfig_t *_pin_config,direction_t *direction_status){
    Std_ReturnType ret = E_OK ;
    if(NULL == _pin_config || NULL == direction_status)
    {
       ret = E_NOT_OK ; 
    }
    else if(_pin_config->Pin_Number > PORT_PIN_MAX_NUMBER-1 || _pin_config->Port >= PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        *direction_status = READ_BIT( *tris_registers[_pin_config->Port] , _pin_config->Pin_Number);
    }
    return ret ;
}
#endif
/**
 * @brief writes logic to a specific pin
 * @param _pin_config : pointer to the configuration @ref pinConfig_t
 * @param logic       : value of logic to write      @ref Logic_t
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution 
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pinConfig_t *_pin_config,logic_t logic){
    Std_ReturnType ret = E_OK ;
    if(NULL == _pin_config)
    {
       ret = E_NOT_OK ; 
    }
    else if(_pin_config->Pin_Number > PORT_PIN_MAX_NUMBER-1 || _pin_config->Port >= PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(logic)
        {
            case (GPIO_LOW)   :
                CLEAR_BIT( *lat_registers[_pin_config->Port] , _pin_config->Pin_Number);
                break;
            case (GPIO_HIGH)  :
                SET_BIT( *lat_registers[_pin_config->Port] , _pin_config->Pin_Number);
                break;
            default            :
                ret = E_NOT_OK ;
        }
    }
    return ret ;
}
#endif
/**
 * @brief reads logic on a specific pin
 * @param _pin_config : pointer to the configuration @ref pinConfig_t
 * @param logic       : pointer to value of logic read   @ref Logic_t
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pinConfig_t *_pin_config,logic_t *logic){
    Std_ReturnType ret = E_OK ;
    if(NULL == _pin_config || NULL == logic)
    {
       ret = E_NOT_OK ; 
    }
    else if(_pin_config->Pin_Number > PORT_PIN_MAX_NUMBER-1 || _pin_config->Port >= PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        *logic = READ_BIT( *port_registers[_pin_config->Port] , _pin_config->Pin_Number);
    }
    return ret ;
}
#endif
/**
 * @brief toggles logic on a specific pin
 * @param _pin_config : pointer to the configuration @ref pinConfig_t
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pinConfig_t *_pin_config){
    Std_ReturnType ret = E_OK ;
    if(NULL == _pin_config)
    {
       ret = E_NOT_OK ; 
    }
    else if(_pin_config->Pin_Number > PORT_PIN_MAX_NUMBER-1 || _pin_config->Port >= PORT_MAX_NUMBER-1)
    {
       ret = E_NOT_OK ;
    }
    else
    {
        TOGGLE_BIT(*lat_registers[_pin_config->Port] , _pin_config->Pin_Number);
    }
    return ret ;
}
#endif
/**
 * @brief initialize direction and logic of a specific pin  @ref direction_t @ref Logic_t
 * @param _pin_config : pointer to the configuration @ref pinConfig_t
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if GPIO_PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_init(const pinConfig_t *_pin_config)
{
    Std_ReturnType ret = E_OK ;
    if(NULL == _pin_config)
    {
       ret = E_NOT_OK ; 
    }
    else if(_pin_config->Pin_Number > PORT_PIN_MAX_NUMBER-1 || _pin_config->Port >= PORT_MAX_NUMBER-1)
    {
       ret = E_NOT_OK ;
    }
    else
    {
        ret = gpio_pin_direction_init(_pin_config);
        ret = gpio_pin_write_logic(_pin_config,_pin_config->Logic);
    }
    return ret ;
}
#endif
/**
 * 
 * @brief initialize direction of a full port
 * @param port         : port index       @ref portIndex_t
 * @param direction    : value of direction from 0x00 To 0xFF
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_direction_init(portIndex_t port, uint8_t direction){
    Std_ReturnType ret = E_OK ;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        *tris_registers[port] = direction ;
    }
    return ret ;
}
#endif
/**
 * @brief read direction of a full port
 * @param port         : port index       @ref portIndex_t
 * @param direction_status    : pointer to a variable to store a value of direction from 0x00 To 0xFF
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(portIndex_t port,uint8_t *direction_status){
    Std_ReturnType ret = E_OK ;
    if(port > PORT_MAX_NUMBER-1 || NULL == direction_status)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        *direction_status = *tris_registers[port] ;
    }
    return ret ;
}
#endif
/**
 * @brief write logic to a full port
 * @param port         : port index       @ref portIndex_t
 * @param logic       :  value of logic read   from 0x00 To 0xFF
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(portIndex_t port,uint8_t logic){
    Std_ReturnType ret = E_OK ;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        *lat_registers[port] = logic;
    }
    return ret ;
}
#endif
/**
 * @brief read logic of a full port
 * @param port         : port index       @ref portIndex_t
 * @param logic : pointer to value of logic read   from 0x00 To 0xFF
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(portIndex_t port,uint8_t *logic){
    Std_ReturnType ret = E_OK ;
    if(port > PORT_MAX_NUMBER-1 || NULL == logic)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        *logic = *port_registers[port] ;
    }
    return ret ;
}
#endif
/**
 * @brief toggle logic of a full port
 * @param port         : port index       @ref portIndex_t
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if GPIO_PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(portIndex_t port){
    Std_ReturnType ret = E_OK ;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        *lat_registers[port] ^= PORTX_MASK ;
    }
    return ret ;
}
#endif
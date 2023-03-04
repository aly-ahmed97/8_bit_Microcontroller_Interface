
#include "ECU_PUSH_BUTTON.h"
/**
 * @brief initialize the required pin to be INPUT
 * @param btn  : pointer to button configuration
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if PUSH_BUTTON_CONTROL == PUSH_BUTTON_ENABLE
Std_ReturnType button_init(const button_t *btn){
    Std_ReturnType ret = E_OK ;
    if(NULL == btn)
    {
       ret = E_NOT_OK ; 
    }
    else
    {
        ret = gpio_pin_direction_init(&(btn->button_pin));
    }
    return ret ;
}
#endif
/**
 * @brief return the state logic on the required pin
 * @param btn  : pointer to button configuration
 * @param state : pointer to store the state value ( PRESSED - RELEASED )
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
#if PUSH_BUTTON_CONTROL == PUSH_BUTTON_ENABLE
Std_ReturnType button_read_state(const button_t *btn,button_state_t *state){
    Std_ReturnType ret = E_OK ;
    button_state_t btn_state = BUTTON_RELEASED ;
    logic_t logic = GPIO_LOW;
    if(NULL == btn)
    {
       ret = E_NOT_OK ; 
    }
    else
    {
        ret = gpio_pin_read_logic(&(btn->button_pin),&logic);
        if(BUTTON_ACTIVE_HIGH == btn->button_active_logic )
        {
            if(GPIO_HIGH == logic)
            {
                *state = BUTTON_PRESSED ;
            }
            else if (GPIO_LOW == logic)
            {
                *state = BUTTON_RELEASED ;
            }
        }
        else if (BUTTON_ACTIVE_LOW == btn->button_active_logic)
        {
            if(GPIO_HIGH == logic)
            {
                *state = BUTTON_RELEASED ;
            }
            else if (GPIO_LOW == logic)
            {
                *state = BUTTON_PRESSED ;
            }  
        }
    }
    return ret ;
}
#endif

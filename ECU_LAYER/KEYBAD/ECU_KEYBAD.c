#include "ECU_KEYBAD.h"
/**
 * @brief funtion to initalize the pins of the matrix keybad
 * @param Keybad pointer to the keybad configutions 
 * @return  status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has is sue to complete execution
 */
#if KEYBAD_CONTROL == KEYBAD_ENABLE
Std_ReturnType keybad_init(const Keybad_t *Keybad){
    Std_ReturnType ret = E_OK ;
    uint8_t Row_Counter = ZERO_INT ;
    uint8_t Columns_Counter = ZERO_INT ;
    if(NULL == Keybad)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        for(Row_Counter = ZERO_INT ; Row_Counter < KEYBAD_ROWS ; Row_Counter++)
        {
            ret = gpio_pin_init(&(Keybad->Rows[Row_Counter]));
        }
        for(Columns_Counter = ZERO_INT ; Columns_Counter < KEYBAD_COLUMNS ; Columns_Counter++)
        {
            ret = gpio_pin_direction_init(&(Keybad->Columns[Columns_Counter]));
        }
    }
    return ret ; 
}
#endif
/**
 * @brief function to get the value have been pressed 
 * @param Keybad pointer to the keybad configutions 
 * @param value uint8 variable to return the value to
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has is sue to complete execution
 */
#if KEYBAD_CONTROL == KEYBAD_ENABLE
Std_ReturnType keybad_get_value(const Keybad_t *Keybad,uint8_t *value){
    Std_ReturnType ret      = E_OK ;
    uint8_t Row_Counter     = ZERO_INT ;
    uint8_t Columns_Counter = ZERO_INT ;
    logic_t logic           = GPIO_LOW ;
    if(NULL == Keybad)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        for(Row_Counter = ZERO_INT ; Row_Counter < KEYBAD_ROWS ; Row_Counter++)
        { 
            ret = gpio_pin_write_logic(&(Keybad->Rows[Row_Counter]),GPIO_LOW);
        }
        for(Row_Counter = ZERO_INT ; Row_Counter < KEYBAD_ROWS ; Row_Counter++)
        {
            ret = gpio_pin_write_logic(&(Keybad->Rows[Row_Counter]),GPIO_HIGH);
            for(Columns_Counter = ZERO_INT ; Columns_Counter < KEYBAD_COLUMNS ; Columns_Counter++)
            {
                ret = gpio_pin_read_logic(&(Keybad->Columns[Columns_Counter]),logic);
                if(GPIO_HIGH == logic)
                {
                    *value = button_Values[Row_Counter][Columns_Counter];
                    break;
                }
                else
                {
                    //nothing
                }      
            }
            ret = gpio_pin_write_logic(&(Keybad->Rows[Row_Counter]),GPIO_LOW);
        }
    }
    return ret ; 
}
#endif
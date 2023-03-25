#include "ECU_CHAR_LCD.h"
static Std_ReturnType lcd_8bit_set_cursor(const char_lcd_8bit_t *lcd,uint8_t row ,uint8_t column);
static Std_ReturnType lcd_4bit_set_cursor(const char_lcd_4bit_t *lcd,uint8_t row ,uint8_t column);
Std_ReturnType lcd_init_4bit(const char_lcd_4bit_t *lcd){
    Std_ReturnType ret = E_OK ;
    uint8_t index = 0 ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = gpio_pin_init(&(lcd->lcd_rs));
        ret = gpio_pin_init(&(lcd->lcd_en));
        for(index = ZERO ; index < 4 ; index++)
        {
           ret = gpio_pin_init(&(lcd->lcd_data[index])); 
        }
        __delay_ms(20);
        ret = lcd_send_command_4bit(lcd,LCD_4BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_send_command_4bit(lcd,LCD_4BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_send_command_4bit(lcd,LCD_4BIT_MODE_2_LINE);
        ret = lcd_send_command_4bit(lcd,LCD_CLEAR);
        ret = lcd_send_command_4bit(lcd,LCD_RETURN_HOME);
        ret = lcd_send_command_4bit(lcd,LCD_ENTRY_MODE);
        ret = lcd_send_command_4bit(lcd,LCD_CURSOR_OFF_DISPLAY_ON);
        ret = lcd_send_command_4bit(lcd,LCD_4BIT_MODE_2_LINE);
    }
    return ret ;
}
Std_ReturnType lcd_send_command_4bit(const char_lcd_4bit_t *lcd, uint8_t command){
    Std_ReturnType ret = E_OK ;
    uint8_t index = 0 ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);
        for(index = ZERO ; index < 4 ; index++)
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[index]),((command>>(4+index))& 0x01 ));
        }
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
        for(index = ZERO ; index < 4 ; index++)
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[index]),((command>>(index))&0x01 ));
        }
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
    }
    return ret ;   
}
Std_ReturnType lcd_send_data_4bit(const char_lcd_4bit_t *lcd, uint8_t data){
    Std_ReturnType ret = E_OK ;
    uint8_t index = 0 ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);
        for(index = ZERO ; index < 4 ; index++)
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[index]),((data>>(4+index))&0x01 ));
        }
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
        for(index = ZERO ; index < 4 ; index++)
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[index]),((data>>(index))&0x01 ));
        }
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
    }
    return ret ;   

}
Std_ReturnType lcd_send_data_pos_4bit(const char_lcd_4bit_t *lcd, uint8_t data,uint8_t column,uint8_t row){
    Std_ReturnType ret = E_OK ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = lcd_4bit_set_cursor(lcd,row,column);
        ret = lcd_send_data_4bit(lcd,data);
    }
    return ret ;   

}
Std_ReturnType lcd_send_string_4bit(const char_lcd_4bit_t *lcd, uint8_t *str){
    Std_ReturnType ret = E_OK ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        while(NULL != *str )
        {
            ret = lcd_send_data_4bit(lcd,*str++);
        }
    }
    return ret ;   

}
Std_ReturnType lcd_send_string_pos_4bit(const char_lcd_4bit_t *lcd, uint8_t *str,uint8_t column,uint8_t row){
    Std_ReturnType ret = E_OK ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {   
        ret = lcd_4bit_set_cursor(lcd,row,column);
        ret = lcd_send_string_4bit(lcd,str);   
    }
    return ret ;   

}

Std_ReturnType lcd_init_8bit(const char_lcd_8bit_t *lcd){
Std_ReturnType ret = E_OK ;
    uint8_t index = 0 ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = gpio_pin_init(&(lcd->lcd_rs));
        ret = gpio_pin_init(&(lcd->lcd_en));
        for(index = ZERO ; index < 8 ; index++)
        {
           ret = gpio_pin_init(&(lcd->lcd_data[index])); 
        }
        __delay_ms(20);
        ret = lcd_send_command_8bit(lcd,LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_send_command_8bit(lcd,LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_send_command_8bit(lcd,LCD_8BIT_MODE_2_LINE);
        ret = lcd_send_command_8bit(lcd,LCD_CLEAR);
        ret = lcd_send_command_8bit(lcd,LCD_RETURN_HOME);
        ret = lcd_send_command_8bit(lcd,LCD_ENTRY_MODE);
        ret = lcd_send_command_8bit(lcd,LCD_CURSOR_OFF_DISPLAY_ON);
        ret = lcd_send_command_8bit(lcd,LCD_8BIT_MODE_2_LINE);
    }
    return ret ;  

}
Std_ReturnType lcd_send_command_8bit(const char_lcd_8bit_t *lcd, uint8_t command){
    Std_ReturnType ret = E_OK ;
    uint8_t index = 0 ; 
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_LOW);
        for(index = ZERO ; index < 8 ; index++)
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[index]),((command>>(index))&0x01 ));
        }
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);
    }
    return ret ;   

}
Std_ReturnType lcd_send_data_8bit(const char_lcd_8bit_t *lcd, uint8_t data){
    Std_ReturnType ret = E_OK ;
    uint8_t index = 0 ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs),GPIO_HIGH);
        for(index = ZERO ; index < 8 ; index++)
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[index]),((data>>(index))&0x01 ));
        }
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(lcd->lcd_en),GPIO_LOW);

    }
    return ret ;   

}
Std_ReturnType lcd_send_data_pos_8bit(const char_lcd_8bit_t *lcd, uint8_t data,uint8_t column,uint8_t row){
    Std_ReturnType ret = E_OK ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = lcd_8bit_set_cursor(lcd,row,column);
        ret = lcd_send_data_8bit(lcd,data);
    }
    return ret ;   

}
Std_ReturnType lcd_send_string_8bit(const char_lcd_8bit_t *lcd, uint8_t *str){
    Std_ReturnType ret = E_OK ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        while(NULL != *str )
        {
            ret = lcd_send_data_8bit(lcd,*str++);
        }
    }
    return ret ;   

}
Std_ReturnType lcd_send_string_pos_8bit(const char_lcd_8bit_t *lcd, uint8_t *str,uint8_t column,uint8_t row){
    Std_ReturnType ret = E_OK ;
    if(NULL == lcd)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = lcd_8bit_set_cursor(lcd,row,column);
        ret = lcd_send_string_8bit(lcd,str);   
    }
    return ret ;   

}


void convert_byte_to_string(uint8_t val,uint8_t *str){
    
}
void convert_short_to_string(uint16_t val,uint8_t *str){
    
}
void convert_int_to_string(uint32_t val,uint8_t *str){
    
}

static Std_ReturnType lcd_8bit_set_cursor(const char_lcd_8bit_t *lcd,uint8_t row ,uint8_t column)
{
    Std_ReturnType ret = E_OK;
    switch(row)
    {
        case ROW0 : ret = lcd_send_command_8bit(lcd,(0x80 + column)); break;
        case ROW1 : ret = lcd_send_command_8bit(lcd,(0xC0 + column)); break;
        case ROW2 : ret = lcd_send_command_8bit(lcd,(0x94 + column)); break;
        case ROW3 : ret = lcd_send_command_8bit(lcd,(0xD4 + column)); break;
        default   : ret = E_NOT_OK ;
    }
    return ret ;
}
static Std_ReturnType lcd_4bit_set_cursor(const char_lcd_4bit_t *lcd,uint8_t row ,uint8_t column)
{
    Std_ReturnType ret = E_OK;
    switch(row)
    {
        case ROW0 : ret = lcd_send_command_8bit(lcd,(0x80 + column)); break;
        case ROW1 : ret = lcd_send_command_8bit(lcd,(0xC0 + column)); break;
        case ROW2 : ret = lcd_send_command_8bit(lcd,(0x94 + column)); break;
        case ROW3 : ret = lcd_send_command_8bit(lcd,(0xD4 + column)); break;
        default   : ret = E_NOT_OK ;
    }
    return ret ;
}
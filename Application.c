/*
 * File:   Application.c
 * Author: Aly Ahmed
 *
 * Created on February 16, 2023, 4:11 PM
 */
#include "ECU_LAYER/CHAR_LCD/ECU_CHAR_LCD.h"
char_lcd_4bit_t lcd1 = {
   .lcd_rs = {
       .Port =       PORTC_INDEX ,
       .Direction =  GPIO_OUTPUT ,
       .Pin_Number = GPIO_PIN0 ,
       .Logic      = GPIO_LOW 
   },
   .lcd_en = {
       .Port =       PORTC_INDEX ,
       .Direction =  GPIO_OUTPUT ,
       .Pin_Number = GPIO_PIN1 ,
       .Logic      = GPIO_LOW 
   },
   .lcd_data[0].Port =       PORTC_INDEX ,
   .lcd_data[0].Direction =  GPIO_OUTPUT ,
   .lcd_data[0].Pin_Number = GPIO_PIN2 ,
   .lcd_data[0].Logic      = GPIO_LOW ,
   .lcd_data[1].Port =       PORTC_INDEX ,
   .lcd_data[1].Direction =  GPIO_OUTPUT ,
   .lcd_data[1].Pin_Number = GPIO_PIN3 ,
   .lcd_data[1].Logic      = GPIO_LOW ,
   .lcd_data[2].Port =       PORTC_INDEX ,
   .lcd_data[2].Direction =  GPIO_OUTPUT ,
   .lcd_data[2].Pin_Number = GPIO_PIN4 ,
   .lcd_data[2].Logic      = GPIO_LOW ,
   .lcd_data[3].Port =       PORTC_INDEX ,
   .lcd_data[3].Direction =  GPIO_OUTPUT ,
   .lcd_data[3].Pin_Number = GPIO_PIN5 ,
   .lcd_data[3].Logic      = GPIO_LOW 
};
char_lcd_8bit_t lcd2 = {
   .lcd_rs = {
       .Port =       PORTC_INDEX ,
       .Direction =  GPIO_OUTPUT ,
       .Pin_Number = GPIO_PIN6 ,
       .Logic      = GPIO_LOW 
   },
   .lcd_en = {
       .Port =       PORTC_INDEX ,
       .Direction =  GPIO_OUTPUT ,
       .Pin_Number = GPIO_PIN7 ,
       .Logic      = GPIO_LOW 
   },
   .lcd_data[0].Port =       PORTD_INDEX ,
   .lcd_data[0].Direction =  GPIO_OUTPUT ,
   .lcd_data[0].Pin_Number = GPIO_PIN0,
   .lcd_data[0].Logic      = GPIO_LOW ,
   .lcd_data[1].Port =       PORTD_INDEX ,
   .lcd_data[1].Direction =  GPIO_OUTPUT ,
   .lcd_data[1].Pin_Number = GPIO_PIN1,
   .lcd_data[1].Logic      = GPIO_LOW ,
   .lcd_data[2].Port =       PORTD_INDEX ,
   .lcd_data[2].Direction =  GPIO_OUTPUT ,
   .lcd_data[2].Pin_Number = GPIO_PIN2,
   .lcd_data[2].Logic      = GPIO_LOW ,
   .lcd_data[3].Port =       PORTD_INDEX ,
   .lcd_data[3].Direction =  GPIO_OUTPUT ,
   .lcd_data[3].Pin_Number = GPIO_PIN3,
   .lcd_data[3].Logic      = GPIO_LOW ,
   .lcd_data[4].Port =       PORTD_INDEX ,
   .lcd_data[4].Direction =  GPIO_OUTPUT ,
   .lcd_data[4].Pin_Number = GPIO_PIN4,
   .lcd_data[4].Logic      = GPIO_LOW ,
   .lcd_data[5].Port =       PORTD_INDEX ,
   .lcd_data[5].Direction =  GPIO_OUTPUT ,
   .lcd_data[5].Pin_Number = GPIO_PIN5,
   .lcd_data[5].Logic      = GPIO_LOW ,
   .lcd_data[6].Port =       PORTD_INDEX ,
   .lcd_data[6].Direction =  GPIO_OUTPUT ,
   .lcd_data[6].Pin_Number = GPIO_PIN6,
   .lcd_data[6].Logic      = GPIO_LOW ,
   .lcd_data[7].Port =       PORTD_INDEX ,
   .lcd_data[7].Direction =  GPIO_OUTPUT ,
   .lcd_data[7].Pin_Number = GPIO_PIN7,
   .lcd_data[7].Logic      = GPIO_LOW ,
};
int main() {
    Std_ReturnType ret = E_NOT_OK ;
    ret= lcd_init_4bit(&lcd1);
    ret= lcd_init_8bit(&lcd2);
    ret= lcd_send_data_8bit(&lcd2,'A');
    ret= lcd_send_data_pos_8bit(&lcd2,'L',5,ROW1);
    ret= lcd_send_data_pos_8bit(&lcd2,'Y',10,ROW2);
    ret= lcd_send_string_pos_8bit(&lcd2,"AHMED",0,ROW3);
    ret= lcd_send_data_4bit(&lcd1,'A');
    ret= lcd_send_data_pos_4bit(&lcd1,'L',5,ROW1);
    ret= lcd_send_data_pos_4bit(&lcd1,'Y',10,ROW2);
    ret= lcd_send_string_pos_4bit(&lcd1,"AHMED",0,ROW3);
    while(1)
    {
        
    }
    return (EXIT_SUCCESS);
}   

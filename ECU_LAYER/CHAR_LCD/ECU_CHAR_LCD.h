/* 
 * File:   ECU_CHAR_LCD.h
 * Author: Aly Ahmed
 *
 * Created on March 11, 2023, 5:13 PM
 */

#ifndef ECU_CHAR_LCD_H
#define	ECU_CHAR_LCD_H
/* Includes Section : */

#include "ECU_CHAR_LCD_CONFIG.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"

/* Macro Declarations Section : */

#define CHAR_LCD_CONTROL CHAR_LCD_ENABLE

#define LCD_CLEAR                    0x01
#define LCD_RETURN_HOME              0x02
#define LCD_ENTRY_MODE               0x06
#define LCD_CURSOR_OFF_DISPLAY_ON    0x0C
#define LCD_CURSOR_OFF_DISPLAY_OFF   0X08
#define LCD_CURSOR_ON_BLINK_ON       0X0F
#define LCD_CURSOR_ON_BLINK_OFF      0X0E
#define LCD_DISPLAY_SHIFT_RIGHT      0X1C
#define LCD_DISPLAY_SHIFT_LEFT       0X18
#define LCD_4BIT_MODE_2_LINE         0X28
#define LCD_8BIT_MODE_2_LINE         0X38
#define LCD_CGRAM_START              0X40
#define LCD_DDRAM_START              0X80

#define ROW0        0
#define ROW1        1
#define ROW2        2
#define ROW3        3

/* Macro Functions Declarations Section : */

/* Data Types Section*/

typedef struct{
  pinConfig_t lcd_rs ;
  pinConfig_t lcd_en ;
  pinConfig_t lcd_data[4];
}char_lcd_4bit_t;

typedef struct{
  pinConfig_t lcd_rs ;
  pinConfig_t lcd_en ;
  pinConfig_t lcd_data[8];
}char_lcd_8bit_t;
/* Functions Declarations Section */

Std_ReturnType lcd_init_4bit(const char_lcd_4bit_t *lcd);
Std_ReturnType lcd_send_command_4bit(const char_lcd_4bit_t *lcd, uint8_t command);
Std_ReturnType lcd_send_data_4bit(const char_lcd_4bit_t *lcd, uint8_t data);
Std_ReturnType lcd_send_data_pos_4bit(const char_lcd_4bit_t *lcd, uint8_t data,uint8_t column,uint8_t row);
Std_ReturnType lcd_send_string_4bit(const char_lcd_4bit_t *lcd, uint8_t *str);
Std_ReturnType lcd_send_string_pos_4bit(const char_lcd_4bit_t *lcd, uint8_t *str,uint8_t column,uint8_t row);

Std_ReturnType lcd_init_8bit(const char_lcd_8bit_t *lcd);
Std_ReturnType lcd_send_command_8bit(const char_lcd_8bit_t *lcd, uint8_t command);
Std_ReturnType lcd_send_data_8bit(const char_lcd_8bit_t *lcd, uint8_t data);
Std_ReturnType lcd_send_data_pos_8bit(const char_lcd_8bit_t *lcd, uint8_t data,uint8_t column,uint8_t row);
Std_ReturnType lcd_send_string_8bit(const char_lcd_8bit_t *lcd, uint8_t *str);
Std_ReturnType lcd_send_string_pos_8bit(const char_lcd_8bit_t *lcd, uint8_t *str,uint8_t column,uint8_t row);

void convert_byte_to_string(uint8_t val,uint8_t *str);
void convert_short_to_string(uint16_t val,uint8_t *str);
void convert_int_to_string(uint32_t val,uint8_t *str);
#endif	/* ECU_CHAR_LCD_H */


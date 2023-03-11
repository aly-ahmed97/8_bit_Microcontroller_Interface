#include "ECU_7_SEGMENTS.h"

/**
 * @brief funtion to initalize the 7 segments pin to be output 
 * @param seg pointer to the 7 segments configutions 
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has is sue to complete execution
 */
#if _7_SEGMENTS_CONTROL == _7_SEGMENTS_ENABLE
Std_ReturnType _7_segments_init(const _7_segments_t *seg){
    Std_ReturnType ret = E_OK ;
    if(NULL == seg)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = gpio_pin_init(&(seg->segment_bits[SEGMENT_PIN0]));
        ret = gpio_pin_init(&(seg->segment_bits[SEGMENT_PIN1]));
        ret = gpio_pin_init(&(seg->segment_bits[SEGMENT_PIN2]));
        ret = gpio_pin_init(&(seg->segment_bits[SEGMENT_PIN3]));
    }
    return ret ; 
}
#endif
/**
 * @brief funtion to write a number from 0 to 9 on a 7 segmenets 
 * @param seg pointer to the 7 segments configutions 
 * @param num the number you want to write on the 7 semgents 
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has is sue to complete execution
 */
#if _7_SEGMENTS_CONTROL == _7_SEGMENTS_ENABLE
Std_ReturnType _7_segments_write_number(const _7_segments_t *seg,uint8_t num){
   Std_ReturnType ret = E_OK ;
    if(NULL == seg || num > 9)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = gpio_pin_write_logic(&(seg->segment_bits[SEGMENT_PIN0]),(num>>SEGMENT_PIN0) & 0x01);
        ret = gpio_pin_write_logic(&(seg->segment_bits[SEGMENT_PIN1]),(num>>SEGMENT_PIN1) & 0x01);
        ret = gpio_pin_write_logic(&(seg->segment_bits[SEGMENT_PIN2]),(num>>SEGMENT_PIN2) & 0x02);
        ret = gpio_pin_write_logic(&(seg->segment_bits[SEGMENT_PIN3]),(num>>SEGMENT_PIN3) & 0x03);
    } 
    return ret ; 
}
#endif

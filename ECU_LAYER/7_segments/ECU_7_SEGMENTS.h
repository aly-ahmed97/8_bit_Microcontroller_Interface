/* 
 * File:   ECU_7_SEGMENTS.h
 * Author: Aly Ahmed
 *
 * Created on March 11, 2023, 1:26 PM
 */

#ifndef ECU_7_SEGMENTS_H
#define	ECU_7_SEGMENTS_H


/* Includes Section : */

#include "ECU_7_SEGMENTS_CONFIG.h"
#include "../../MCAL_LAYER/GPIO/HAL_GPIO.h"

/* Macro Declarations Section : */

#define _7_SEGMENTS_CONTROL _7_SEGMENTS_ENABLE

#define SEGMENT_PIN0 0 
#define SEGMENT_PIN1 1 
#define SEGMENT_PIN2 2 
#define SEGMENT_PIN3 3 
/* Macro Functions Declarations Section : */


/* Data Types Section*/

typedef enum{
    _7_SEGMENTS_COMMON_ANODE = 0 ,
    _7_SEGMENTS_COMMON_CATHODE        
}_7_segments_type_t;
typedef struct{
    pinConfig_t         segment_bits[4];
    _7_segments_type_t   type ;
}_7_segments_t;

/* Functions Declarations Section */

Std_ReturnType _7_segments_init(const _7_segments_t *seg);
Std_ReturnType _7_segments_write_number(const _7_segments_t *seg,uint8_t num);
#endif	/* ECU_7_SEGMENTS_H */


/* 
 * File:   MCAL_STD_TYPES.h
 * Author: Aly Ahmed
 *
 * Created on February 16, 2023, 5:19 PM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Includes Section : */

#include "COMPILER.h"
#include "STD_LIBRARIES.h"

/* Data Types Section*/

typedef unsigned char uint8_t ;
typedef unsigned short uint16_t ;
typedef unsigned long uint32_t ;
typedef signed char sint8_t ;
typedef signed short sint16_t ; 
typedef signed long sint32_t ;

typedef uint8_t Std_ReturnType ;

/* Macro Declarations Section : */

#define STD_HIGH        0x01
#define STD_LOW         0x00

#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDEAL       0x00

#define E_OK            (Std_ReturnType)0x01
#define E_NOT_OK        (Std_ReturnType)0x00

/* Macro Functions Declarations Section : */

/* Functions Declarations Section */

#endif	/* MCAL_STD_TYPES_H */


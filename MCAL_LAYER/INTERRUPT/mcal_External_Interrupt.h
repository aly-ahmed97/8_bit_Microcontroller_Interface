/* 
 * File:   mcal_External_Interrupt.h
 * Author: Aly Ahmed
 *
 * Created on March 31, 2023, 2:12 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* Includes Section : */

#include "mcal_Interrupt_config.h"

/* Macro Declarations Section : */

/* Macro Functions Declarations Section : */
#if INTURRUPT_EXTERNAL_INTX_FEATURE_ENABLE == INTURRUPT_FEATURE_ENABLE
    #define   INT0_InterruptDisable()            (INTCONbits.INT0E =    0x00)
    #define   INT0_InterruptEnable()             (INTCONbits.INT0E =    0x01)
    #define   INT0_InterruptFlagClear()          (INTCONbits.INT0F =    0x00)
    #define   INT0_InterruptRisingEdgeSet()      (INTCON2bits.INTEDG0 = 0x01)
    #define   INT0_InterruptFallingEdgeSet()     (INTCON2bits.INTEDG0 = 0x00)

    #define   INT1_InterruptDisable()            (INTCON3bits.INT1E =   0x00)
    #define   INT1_InterruptEnable()             (INTCON3bits.INT1E =   0x01)
    #define   INT1_InterruptFlagClear()          (INTCON3bits.INT1F =   0x00)
    #define   INT1_InterruptRisingEdgeSet()      (INTCON2bits.INTEDG1 = 0x01)
    #define   INT1_InterruptFallingEdgeSet()     (INTCON2bits.INTEDG1 = 0x00)

    #define   INT2_InterruptDisable()            (INTCON3bits.INT2E =   0x00)
    #define   INT2_InterruptEnable()             (INTCON3bits.INT2E =   0x01)
    #define   INT2_InterruptFlagClear()          (INTCON3bits.INT2F =   0x00)
    #define   INT2_InterruptRisingEdgeSet()      (INTCON2bits.INTEDG2 = 0x01)
    #define   INT2_InterruptFallingEdgeSet()     (INTCON2bits.INTEDG2 = 0x00)
    #if INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_ENABLE

        #define INT1_HighPrioritySet() (INTCON3bits.INT1P = 0x01)
        #define INT1_LowPrioritySet()  (INTCON3bits.INT1P = 0x00)

        #define INT2_HighPrioritySet() (INTCON3bits.INT2P = 0x01)
        #define INT2_LowPrioritySet()  (INTCON3bits.INT2P = 0x00)

    #endif
#endif
/* #if INTURRUPT_EXTERNAL_ONCHANGE_FEATURE_ENABLE == INTURRUPT_FEATURE_ENABLE
    #define   PORTB_OnChange_InterruptDisable()            (INTCONbits.RBIE =    0x00)
    #define   PORTB_OnChange_InterruptEnable()             (INTCONbits.RBIE =    0x01)
    #define   PORTB_OnChange_InterruptFlagClear()          (INTCONbits.RBIF =    0x00)
    #if INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_ENABLE
        #define PORTB_OnChange_HighPrioritySet() (INTCON2bits.RBIP = 0x01)
        #define PORTB_OnChange_LowPrioritySet()  (INTCON2bits.RBIP = 0x00)
    #endif
#endif */
/* Data Types Section*/
typedef enum{
    FALLING_EDGE = 0,
    RISING_EDGE 
}INTx_Interrupt_Edge;
typedef enum{
    Ext_INT0 = 0,
    Ext_INT1,
    Ext_INT2
}INTx_Src;
typedef struct{
    INTx_Interrupt_Edge     EDGE     ;
    INTx_Src                SRC      ;
    Interrupt_priority_cfg  PRIORITY ;
    pinConfig_t             PIN      ;
    void                    (*EX_Int_Handler)(void);
}Inturrupt_INTx_t;
/*
typedef struct{
    Interrupt_priority_cfg  PRIORITY ;
    pinConfig_t             PIN      ;
    void                    (*EX_Int_Handler)(void);
}Inturrupt_RBx_t;
 * */
/* Functions Declarations Section */

Std_ReturnType Interrupt_INTx_Init(const Inturrupt_INTx_t *Int_Obj);
Std_ReturnType Interrupt_INTx_Stop(const Inturrupt_INTx_t *Int_Obj );
/*
Std_ReturnType Interrupt_RBx_Init(const Inturrupt_RBx_t *Int_Obj);
Std_ReturnType Interrupt_RBx_Stop(const Inturrupt_RBx_t *Int_Obj );
*/
#endif	/* MCAL_EXTERNALL_INTERRUPT_H */


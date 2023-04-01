#include "mcal_Interrupt_Manager.h"
/*
 you can change the periority in the main application and you must change here the place of the interrupt to the right place 
 */
#if INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_ENABLE
void __interrupt() InterruptMangerHigh(void){
    if(INTCONbits.INT0E == INTERUPPT_ENABLE && INTCONbits.INT0F == INTURRUPT_OCCUR){
        void INT0_ISR(void);
    }
    else{
        //nothing
    }
    if(INTCON3bits.INT1E == INTERUPPT_ENABLE && INTCON3bits.INT1F == INTURRUPT_OCCUR){
        void INT1_ISR(void);
    }
    else{
        //nothing
    }
}
void __interrupt(low_priority) InterruptMangerLow(void){
    if(INTCON3bits.INT2E == INTERUPPT_ENABLE && INTCON3bits.INT2F == INTURRUPT_OCCUR){
        void INT2_ISR(void);
    }
    else{
        //nothing
    }
}
#elif INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_DISABLE
void __interrupt() InterruptMangerHigh(void){
    if(INTCONbits.INT0E == INTERUPPT_ENABLE && INTCONbits.INT0F == INTURRUPT_OCCUR){
        void INT0_ISR(void);
    }
    else{
    //nothing 
    }
    if(INTCON3bits.INT1E == INTERUPPT_ENABLE && INTCON3bits.INT1F == INTURRUPT_OCCUR){
        void INT1_ISR(void);
    }
    else{
    //nothing 
    }
    if(INTCON3bits.INT2E == INTERUPPT_ENABLE && INTCON3bits.INT2F == INTURRUPT_OCCUR){
        void INT2_ISR(void);
    }
    else{
    //nothing 
    }
}
#endif 
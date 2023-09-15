#include "mcal_External_Interrupt.h"

static void (*Int0_Interrupt_Handller)(void) = NULL ;
static void (*Int1_Interrupt_Handller)(void) = NULL ;
static void (*Int2_Interrupt_Handller)(void) = NULL ;

static Std_ReturnType Interrupt_INTx_Enable(const Inturrupt_INTx_t *Int_Obj );
static Std_ReturnType Interrupt_INTx_Disable(const Inturrupt_INTx_t *Int_Obj );
static Std_ReturnType Interrupt_INTx_Priority_Init(const Inturrupt_INTx_t *Int_Obj );
static Std_ReturnType Interrupt_INTx_Edge_Init(const Inturrupt_INTx_t *Int_Obj );
static Std_ReturnType Interrupt_INTx_Pin_Init(const Inturrupt_INTx_t *Int_Obj );
static Std_ReturnType Interrupt_INTx_Clear_Flag(const Inturrupt_INTx_t *Int_Obj );

static Std_ReturnType Set_INT0_Interrupt_Handller(void (*Int_Interrupt_Handller)(void));
static Std_ReturnType Set_INT1_Interrupt_Handller(void (*Int_Interrupt_Handller)(void));
static Std_ReturnType Set_INT2_Interrupt_Handller(void (*Int_Interrupt_Handller)(void));

static Std_ReturnType Set_INTx_Interrupt_Handller(const Inturrupt_INTx_t *Int_Obj);

/**
 * @BRIEF Function to start exertrnal Interrupt
 * @param Int_Obj : Pointer to the PIN COnfigutations 
 * @return status of the function :
 *        (E_OK) if function executed successfully 
 *        (E_NOT_OK) if function has issue to complete execution
 */
Std_ReturnType Interrupt_INTx_Init(const Inturrupt_INTx_t *Int_Obj){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Obj)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = Interrupt_INTx_Disable(Int_Obj);
        ret = Interrupt_INTx_Clear_Flag(Int_Obj);
        ret = Interrupt_INTx_Pin_Init(Int_Obj);
        #if INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_ENABLE
            ret = Interrupt_INTx_Priority_Init(Int_Obj);
        #endif
        ret = Interrupt_INTx_Edge_Init(Int_Obj);
        ret = Set_INTx_Interrupt_Handller(Int_Obj);
        ret = Interrupt_INTx_Enable(Int_Obj);
    }
    return ret ;
}
/*Std_ReturnType Interrupt_RBx_Init(const Inturrupt_RBx_t *Int_Obj){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Obj)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = PORTB_OnChange_InterruptDisable();
        ret = PORTB_OnChange_InterruptFlagClear();
        #if INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_ENABLE
            ret = Interrupt_RBx_Priority_Init(Int_Obj);
        #endif
        ret = Set_INTx_Interrupt_Handller(Int_Obj);
        ret = PORTB_OnChange_InterruptEnable();
    }
    return ret ;
}*/
static Std_ReturnType Interrupt_INTx_Enable(const Inturrupt_INTx_t *Int_Obj ){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Obj)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(Int_Obj->SRC){
              case (Ext_INT0):   
                  #if INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_ENABLE
                    INTURRUPT_GlobalInterruptPriorityEnable();  
                    INTURRUPT_GlobalInterruptHighEnable();
                    INTURRUPT_GlobalInterruptLowEnable();
                  #elif INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_DISABLE
                    INTURRUPT_GlobalInterruptEnable();
                    INTURRUPT_PeripheralInterruptEnable();
                  #endif
                  INT0_InterruptEnable();
                  break ;
              case (Ext_INT1):  
                  #if INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_ENABLE
                    INTURRUPT_GlobalInterruptPriorityEnable();  
                    INTURRUPT_GlobalInterruptHighEnable();
                    INTURRUPT_GlobalInterruptLowEnable();
                  #elif INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_DISABLE
                    INTURRUPT_GlobalInterruptEnable();
                    INTURRUPT_PeripheralInterruptEnable();
                  #endif
                  INT1_InterruptEnable();
                  break ;
              case (Ext_INT2):   
                  #if INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_ENABLE
                    INTURRUPT_GlobalInterruptPriorityEnable();  
                    INTURRUPT_GlobalInterruptHighEnable();
                    INTURRUPT_GlobalInterruptLowEnable();
                  #elif INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_DISABLE
                    INTURRUPT_GlobalInterruptEnable();
                    INTURRUPT_PeripheralInterruptEnable();
                  #endif
                  INT2_InterruptEnable();
                  break ;
              default :      ret = E_NOT_OK;
        }
    }
    return ret ;
}
static Std_ReturnType Interrupt_INTx_Disable(const Inturrupt_INTx_t *Int_Obj ){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Obj)
    {
        ret = E_NOT_OK ;
    }
    else
    {
      switch(Int_Obj->SRC){
            case (Ext_INT0):   INT0_InterruptDisable(); break ;
            case (Ext_INT1):   INT1_InterruptDisable(); break ;
            case (Ext_INT2):   INT2_InterruptDisable(); break ;
            default :      ret = E_NOT_OK;   
      }
    }
    return ret ;   
}
#if INTURRUPT_PRIORITY_LEVELS_ENABLE == INTURRUPT_FEATURE_ENABLE
static Std_ReturnType Interrupt_INTx_Priority_Init(const Inturrupt_INTx_t *Int_Obj ){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Obj)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(Int_Obj->SRC){
            case (Ext_INT1):   
                switch(Int_Obj->PRIORITY){
                        case (HIGH_Priority) :  INT1_HighPrioritySet();   break;
                        case (LOW_Priority)  :  INT1_LowPrioritySet();    break;
                        default : ret = E_NOT_OK ;
                }
            case (Ext_INT2):
                switch(Int_Obj->PRIORITY){
                        case (HIGH_Priority) :  INT2_HighPrioritySet();   break;
                        case (LOW_Priority)  :  INT2_LowPrioritySet();    break;
                        default : ret = E_NOT_OK ;
                }
            default :      ret = E_NOT_OK;
        }
    }
    return ret ;
}
#endif
static Std_ReturnType Interrupt_INTx_Edge_Init(const Inturrupt_INTx_t *Int_Obj ){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Obj)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(Int_Obj->SRC){
            case (Ext_INT0):   
                switch(Int_Obj->EDGE){
                        case (RISING_EDGE) :    INT0_InterruptRisingEdgeSet();   break;
                        case (FALLING_EDGE):    INT0_InterruptFallingEdgeSet();    break;
                        default : ret = E_NOT_OK ;
                }
            case (Ext_INT1):   
                switch(Int_Obj->EDGE){
                        case (RISING_EDGE) :    INT1_InterruptRisingEdgeSet();   break;
                        case (FALLING_EDGE):    INT1_InterruptFallingEdgeSet();    break;
                        default : ret = E_NOT_OK ;
                }
            case (Ext_INT2):
                switch(Int_Obj->PRIORITY){
                        case (RISING_EDGE) :    INT2_InterruptRisingEdgeSet();   break;
                        case (FALLING_EDGE):    INT2_InterruptFallingEdgeSet();    break;
                        default : ret = E_NOT_OK ;
                }
            default :      ret = E_NOT_OK; 
        }
    }
    return ret ;
}
static Std_ReturnType Interrupt_INTx_Pin_Init(const Inturrupt_INTx_t *Int_Obj ){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Obj)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        ret = gpio_pin_direction_init(&(Int_Obj->PIN));
    }
    return ret ;
}
static Std_ReturnType Interrupt_INTx_Clear_Flag(const Inturrupt_INTx_t *Int_Obj ){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Obj)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(Int_Obj->SRC){
            case (Ext_INT0):   INT0_InterruptFlagClear(); break ;
            case (Ext_INT1):   INT1_InterruptFlagClear(); break ;
            case (Ext_INT2):   INT2_InterruptFlagClear(); break ;
            default :      ret = E_NOT_OK;   
      }
    }
    return ret ;
}

static Std_ReturnType Set_INT0_Interrupt_Handller(void (*Int_Interrupt_Handller)(void)){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Interrupt_Handller)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        Int0_Interrupt_Handller = Int_Interrupt_Handller ;
    }
    return ret ;
}
static Std_ReturnType Set_INT1_Interrupt_Handller(void (*Int_Interrupt_Handller)(void)){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Interrupt_Handller)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        Int1_Interrupt_Handller = Int_Interrupt_Handller ;
    }
    return ret ;  
}
static Std_ReturnType Set_INT2_Interrupt_Handller(void (*Int_Interrupt_Handller)(void)){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Interrupt_Handller)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        Int2_Interrupt_Handller = Int_Interrupt_Handller ;
    }
    return ret ;    
}

static Std_ReturnType Set_INTx_Interrupt_Handller(const Inturrupt_INTx_t *Int_Obj){
    Std_ReturnType ret = E_OK ;
    if(NULL == Int_Obj)
    {
        ret = E_NOT_OK ;
    }
    else
    {
        switch(Int_Obj->SRC){
            case (Ext_INT0):   ret = Set_INT0_Interrupt_Handller(&(Int_Obj->EX_Int_Handler)); break ;
            case (Ext_INT1):   ret = Set_INT1_Interrupt_Handller(&(Int_Obj->EX_Int_Handler)); break ;
            case (Ext_INT2):   ret = Set_INT2_Interrupt_Handller(&(Int_Obj->EX_Int_Handler)); break ;
            default :      ret = E_NOT_OK;   
      }
    }
    return ret ;
}
void INT0_ISR(void){
    INT0_InterruptFlagClear();
    /* CODE HERE*/
    if(Int0_Interrupt_Handller)
    {
        Int0_Interrupt_Handller();
    }
}
void INT1_ISR(void){
    INT1_InterruptFlagClear();
    /* CODE HERE*/
    if(Int1_Interrupt_Handller)
    {
        Int1_Interrupt_Handller();
    }
}
void INT2_ISR(void){
    INT2_InterruptFlagClear();
    /* CODE HERE*/
    if(Int2_Interrupt_Handller)
    {
        Int2_Interrupt_Handller();
    }
}


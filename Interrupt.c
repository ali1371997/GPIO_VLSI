#include "STD_TYPES.h"
#include "RegMap.h"
#include"Interrupt.h"


void (*PtrGPIOPortA)(void);
void (*PtrGPIOPortB)(void);
void (*PtrGPIOPortC)(void);
void (*PtrGPIOPortD)(void);
void (*PtrGPIOPortE)(void);
void (*PtrUART0)(void);
void (*PtrUART1)(void);
void (*PtrSSI0)(void);
void (*PtrI2C0)(void);
void (*PtrPWMFault)(void);
void (*PtrPWM0Generator_0)(void);
void (*PtrPWM0Generator_1)(void);
void (*PtrPWM0Generator_2)(void);
void (*PtrQuadratureEncoder_0)(void);
void (*PtrADCSequence_0)(void);
void (*PtrADCSequence_1)(void);
void (*PtrADCSequence_2)(void);
void (*PtrADCSequence_3)(void);
void (*PtrWatchdogTimer)(void);
void (*PtrTimer0_subtimerA)(void);
void (*PtrTimer0_SubtimerB)(void);
void (*PtrTimer1_SubtimerA)(void);
void (*PtrTimer1_SubtimerB)(void);
void (*PtrTimer2_SubtimerA)(void);
void (*PtrTimer2_SubtimerB)(void);
void (*PtrAnalogComparator_0)(void);
void (*PtrAnalogComparator_1)(void);
void (*PtrAnalogComparator_2)(void);
void (*PtrSystemControl)(void);
void (*PtrFLASHControl)(void);
void (*PtrGPIOPortF)(void);
void (*PtrGPIOPortG)(void);
void (*PtrGPIOPortH)(void);
void (*PtrUART2)(void);
void (*PtrSSI1)(void);
void (*PtrTimer3_SubtimerA)(void);
void (*PtrTimer3_SubtimerB)(void);
void (*PtrI2C1)(void);
void (*PtrQuadratureEncoder_1)(void);
void (*PtrCAN0)(void);
void (*PtrCAN1)(void);
void (*PtrHibernate)(void);
void (*PtrUSB0)(void);
void (*PtrPWM0Generator_3)(void);
void (*PtruDMASoftwareTransfer)(void);
void (*PtruDMAError)(void);
void (*PtrADC1Sequence_0)(void);
void (*PtrADC1Sequence_1)(void);
void (*PtrADC1Sequence_2)(void);
void (*PtrADC1Sequence_3)(void);
void (*PtrGPIOPortJ )(void);
void (*PtrGPIOPortK)(void);
void (*PtrGPIOPortL)(void);
void (*PtrSSI2)(void);
void (*PtrSSI3)(void);
void (*PtrUART3)(void);
void (*PtrUART4)(void);
void (*PtrUART5)(void);
void (*PtrUART6)(void);
void (*PtrUART7)(void);
void (*PtrI2C2)(void);
void (*PtrI2C3)(void);
void (*PtrTimer4SubtimerA)(void);
void (*PtrTimer4_SubtimerB)(void);
void (*PtrTimer5_subtimerA)(void);
void (*PtrTimer5_SubtimerB)(void);
void (*PtrWideTimer0_SubtimerA)(void);
void (*PtrWideTimer0_SubtimerB)(void);
void (*PtrWideTimer1_SubtimerA)(void);
void (*PtrWideTimer1_SubtimerB)(void);
void (*PtrWideTimer2_SubtimerA)(void);
void (*PtrWideTimer2_SubtimerB)(void);
void (*PtrWideTimer3_SubtimerA)(void);
void (*PtrWideTimer3_SubtimerB)(void);
void (*PtrWideTimer4_SubtimerA)(void);
void (*PtrWideTimer4_SubtimerB)(void);
void (*PtrWideTimer5_SubtimerA)(void);
void (*PtrWideTimer5_SubtimerB)(void);
void (*PtrFPU)(void);
void (*PtrPWM1Generator_0)(void);
void (*PtrPWM1Generator_1)(void);
void (*PtrPWM1Generator_2)(void);
void (*PtrPWM1Generator_3)(void);
void (*PtrPWM1Fault)(void);



void IntEnable(InterrupptID_t Int)
{

    uint8 RegOffset = Int / 32;
    RegOffset = RegOffset * 4;
    uint8 shift = Int % 32;

    (*((volatile uint32*) (RegOffset + Int_EN))) |= (1 << shift);

}

void IntDisable(InterrupptID_t Int)
{

    uint8 RegOffset = Int / 32;
    RegOffset = RegOffset * 4;
    uint8 shift = Int % 32;

    (*((volatile uint32*) (RegOffset + Int_DIS))) |= (1 << shift);

}

void IntSetPending(InterrupptID_t Int)
{
    uint8 RegOffset = Int / 32;
    RegOffset = RegOffset * 4;
    uint8 shift = Int % 32;

    (*((volatile uint32*) (RegOffset + Int_PEND))) |= (1 << shift);

}
void IntClearPending(InterrupptID_t Int)
{
    uint8 RegOffset = Int / 32;
    RegOffset = RegOffset * 4;
    uint8 shift = Int % 32;

    (*((volatile uint32*) (RegOffset + Int_UNPEND))) |= (1 << shift);

}
IntPending_t IntGetPending(InterrupptID_t Int)
{
    uint32 pend;
    uint8 RegOffset = Int / 32;
    RegOffset = RegOffset * 4;
    uint8 shift = Int % 32;

    pend = (*((volatile uint32*) (RegOffset + Int_PEND)));
    pend &= (1 << shift);
    pend = (pend >> shift);
    return pend;
}

IntActive_t IntGetActive(InterrupptID_t Int)
{
    uint32 active;
    uint8 RegOffset = Int / 32;
    RegOffset = RegOffset * 4;
    uint8 shift = Int % 32;

    active = (*((volatile uint32*) (RegOffset + Int_ACTIVE)));
    active &= (1 << shift);
    active = (active >> shift);

    return active;

}

void IntSetPriority(InterrupptID_t Int, uint8 priority)
{
    uint8 RegOffset = Int / 4;
    RegOffset = RegOffset * 4;
    uint8 shift = Int % 4;

    (*((volatile uint32*) (RegOffset + Int_PRI))) |= (priority
            << ((shift * 8) + 5));

}

uint8 IntGetPriority(InterrupptID_t Int)
{
    uint8 RegOffset = Int / 4;
    RegOffset = RegOffset * 4;
    uint8 shift = Int % 4;
    uint32 priority = 0;

    priority = (*((volatile uint32*) (RegOffset + Int_PRI)));
    priority &= (1 << ((shift * 8) + 5));
    priority = (priority >> ((shift * 8) + 5));
    return priority;
}




/*callback function to choose which funtion to  be handeled when interrupt happens*/

/*ISRRegister Function*/

void IntRegister(void (*ptr1)(void), InterrupptID_t Int)
{
    if(Int== GPIOPortA ){            PtrGPIOPortA                    =ptr1;}
    else if(Int== GPIOPortB){             PtrGPIOPortB                        =ptr1;}
    else if(Int== GPIOPortC){             PtrGPIOPortC                        =ptr1;}
    else if(Int== GPIOPortD){             PtrGPIOPortD                        =ptr1;}
    else if(Int== GPIOPortE){             PtrGPIOPortE                        =ptr1;}
    else if(Int== UART0){                 PtrUART0                        =ptr1;}
    else if(Int== UART1){                 PtrUART1                        =ptr1;}
    else if(Int== SSI0){                  PtrSSI0                     =ptr1;}
    else if(Int== I2C0){                  PtrI2C0                     =ptr1;}
    else if(Int== PWMFault){              PtrPWMFault                     =ptr1;}
    else if(Int== PWM0Generator_0){       PtrPWM0Generator_0                      =ptr1;}
    else if(Int== PWM0Generator_1){       PtrPWM0Generator_1                      =ptr1;}
    else if(Int== PWM0Generator_2){       PtrPWM0Generator_2                      =ptr1;}
    else if(Int== QuadratureEncoder_0){   PtrQuadratureEncoder_0                      =ptr1;}
    else if(Int== ADCSequence_0){         PtrADCSequence_0                        =ptr1;}
    else if(Int== ADCSequence_1){         PtrADCSequence_1                        =ptr1;}
    else if(Int== ADCSequence_2){         PtrADCSequence_2                        =ptr1;}
    else if(Int== ADCSequence_3){         PtrADCSequence_3                        =ptr1;}
    else if(Int== WatchdogTimer){         PtrWatchdogTimer                        =ptr1;}
    else if(Int== Timer0_subtimerA){      PtrTimer0_subtimerA                     =ptr1;}
    else if(Int== Timer0_SubtimerB){      PtrTimer0_SubtimerB                     =ptr1;}
    else if(Int== Timer1_SubtimerA){      PtrTimer1_SubtimerA                     =ptr1;}
    else if(Int== Timer1_SubtimerB){      PtrTimer1_SubtimerB                     =ptr1;}
    else if(Int== Timer2_SubtimerA){      PtrTimer2_SubtimerA                     =ptr1;}
    else if(Int== Timer2_SubtimerB){      PtrTimer2_SubtimerB                     =ptr1;}
    else if(Int== AnalogComparator_0){    PtrAnalogComparator_0                   =ptr1;}
    else if(Int== AnalogComparator_1){    PtrAnalogComparator_1                   =ptr1;}
    else if(Int== AnalogComparator_2){    PtrAnalogComparator_2                   =ptr1;}
    else if(Int== SystemControl){         PtrSystemControl                        =ptr1;}
    else if(Int== FLASHControl){          PtrFLASHControl                     =ptr1;}
    else if(Int== GPIOPortF){             PtrGPIOPortF                        =ptr1;}
    else if(Int== GPIOPortG){             PtrGPIOPortG                        =ptr1;}
    else if(Int== GPIOPortH){             PtrGPIOPortH                        =ptr1;}
    else if(Int== UART2){                 PtrUART2                        =ptr1;}
    else if(Int== SSI1){                  PtrSSI1                     =ptr1;}
    else if(Int== Timer3_SubtimerA){      PtrTimer3_SubtimerA                     =ptr1;}
    else if(Int== Timer3_SubtimerB){      PtrTimer3_SubtimerB                     =ptr1;}
    else if(Int== I2C1){                  PtrI2C1                     =ptr1;}
    else if(Int== QuadratureEncoder_1){   PtrQuadratureEncoder_1                      =ptr1;}
    else if(Int== CAN0){                  PtrCAN0                     =ptr1;}
    else if(Int== CAN1){                  PtrCAN1                     =ptr1;}
    else if(Int== Hibernate){             PtrHibernate                        =ptr1;}
    else if(Int== USB0){                  PtrUSB0                     =ptr1;}
    else if(Int== PWM0Generator_3){       PtrPWM0Generator_3                      =ptr1;}
    else if(Int== uDMASoftwareTransfer){  PtruDMASoftwareTransfer                     =ptr1;}
    else if(Int== uDMAError){             PtruDMAError                        =ptr1;}
    else if(Int== ADC1Sequence_0){        PtrADC1Sequence_0                   =ptr1;}
    else if(Int== ADC1Sequence_1){        PtrADC1Sequence_1                   =ptr1;}
    else if(Int== ADC1Sequence_2){        PtrADC1Sequence_2                   =ptr1;}
    else if(Int== ADC1Sequence_3){        PtrADC1Sequence_3                   =ptr1;}
    else if(Int== GPIOPortJ ){            PtrGPIOPortJ                  =ptr1;}
    else if(Int== GPIOPortK){             PtrGPIOPortK                        =ptr1;}
    else if(Int== GPIOPortL){             PtrGPIOPortL                        =ptr1;}
    else if(Int== SSI2){                  PtrSSI2                     =ptr1;}
    else if(Int== SSI3){                  PtrSSI3                     =ptr1;}
    else if(Int== UART3){                 PtrUART3                        =ptr1;}
    else if(Int== UART4){                 PtrUART4                        =ptr1;}
    else if(Int== UART5){                 PtrUART5                        =ptr1;}
    else if(Int== UART6){                 PtrUART6                        =ptr1;}
    else if(Int== UART7){                 PtrUART7                        =ptr1;}
    else if(Int== I2C2 ){                 PtrI2C2                         =ptr1;}
    else if(Int== I2C3){                  PtrI2C3                     =ptr1;}
    else if(Int== Timer4SubtimerA){       PtrTimer4SubtimerA                      =ptr1;}
    else if(Int== Timer4_SubtimerB){      PtrTimer4_SubtimerB                     =ptr1;}
    else if(Int== Timer5_subtimerA ){     PtrTimer5_subtimerA                         =ptr1;}
    else if(Int== Timer5_SubtimerB){      PtrTimer5_SubtimerB                     =ptr1;}
    else if(Int== WideTimer0_SubtimerA){  PtrWideTimer0_SubtimerA                     =ptr1;}
    else if(Int== WideTimer0_SubtimerB){  PtrWideTimer0_SubtimerB                     =ptr1;}
    else if(Int== WideTimer1_SubtimerA){  PtrWideTimer1_SubtimerA                     =ptr1;}
    else if(Int== WideTimer1_SubtimerB){  PtrWideTimer1_SubtimerB                     =ptr1;}
    else if(Int== WideTimer2_SubtimerA){  PtrWideTimer2_SubtimerA                     =ptr1;}
    else if(Int== WideTimer2_SubtimerB){  PtrWideTimer2_SubtimerB                     =ptr1;}
    else if(Int== WideTimer3_SubtimerA){  PtrWideTimer3_SubtimerA                     =ptr1;}
    else if(Int== WideTimer3_SubtimerB){  PtrWideTimer3_SubtimerB                     =ptr1;}
    else if(Int== WideTimer4_SubtimerA){  PtrWideTimer4_SubtimerA                     =ptr1;}
    else if(Int== WideTimer4_SubtimerB){  PtrWideTimer4_SubtimerB                     =ptr1;}
    else if(Int== WideTimer5_SubtimerA){  PtrWideTimer5_SubtimerA                     =ptr1;}
    else if(Int== WideTimer5_SubtimerB){  PtrWideTimer5_SubtimerB                     =ptr1;}
    else if(Int== FPU){                      PtrFPU                                   =ptr1;}
    else if(Int== PWM1Generator_0 ){      PtrPWM1Generator_0                          =ptr1;}
    else if(Int== PWM1Generator_1){       PtrPWM1Generator_1                          =ptr1;}
    else if(Int== PWM1Generator_2){       PtrPWM1Generator_2                          =ptr1;}
    else if(Int== PWM1Generator_3){       PtrPWM1Generator_3                          =ptr1;}
    else if(Int== PWM1Fault){             PtrPWM1Fault                                =ptr1;}

}

extern void ISR_GPIOPortA(void)
{
    (*PtrGPIOPortA)();
}
extern void ISR_GPIOPortB(void)
{
    (*PtrGPIOPortB)();
}
extern void ISR_GPIOPortC(void)
{
    (*PtrGPIOPortC)();
}
extern void ISR_GPIOPortD(void)
{
    (*PtrGPIOPortD)();
}
extern void ISR_GPIOPortE(void)
{
    (*PtrGPIOPortE)();
}
extern void ISR_Uart0(void)
{
    (*PtrUART0)();
}
extern void ISR_Uart1(void)
{
    (*PtrUART1)();
}
extern void ISR_SSI0(void)
{
    (*PtrSSI0)();
}
extern void ISR_I2C0(void)
{
    (*PtrI2C0)();
}
extern void ISR_PWM0Fault(void)
{
    (*PtrPWMFault)();
}
extern void ISR_PWM0Genretaor0(void)
{
    (*PtrPWM0Generator_0)();
}
extern void ISR_PWM0Genretaor1(void)
{
    (*PtrPWM0Generator_1)();
}
extern void ISR_PWM0Genretaor2(void)
{
    (*PtrPWM0Generator_2)();
}
extern void ISR_QuadEncoder0(void)
{
    (*PtrQuadratureEncoder_0)();
}
extern void ISR_ADC0(void)
{
    (*PtrADCSequence_0)();
}
extern void ISR_ADC1(void)
{
    (*PtrADCSequence_1)();
}
extern void ISR_ADC2(void)
{
    (*PtrADCSequence_2)();
}
extern void ISR_ADC3(void)
{
    (*PtrADCSequence_3)();
}
extern void ISR_WatchdogTimer(void)
{
    (*PtrWatchdogTimer)();
}
extern void ISR_Timer0_A(void)
{
    (*PtrTimer0_subtimerA)();
}
extern void ISR_Timer0_B(void)
{
    (*PtrTimer0_SubtimerB)();
}
extern void ISR_Timer1_A(void)
{
    (*PtrTimer1_SubtimerA)();
}
extern void ISR_Timer1_B(void)
{
    (*PtrTimer1_SubtimerB)();
}
extern void ISR_Timer2_A(void)
{
    (*PtrTimer2_SubtimerA)();
}
extern void ISR_Timer2_B(void)
{
    (*PtrTimer2_SubtimerB)();
}
extern void ISR_Analogcomp0(void)
{
    (*PtrAnalogComparator_0)();
}
extern void ISR_Analogcomp1(void)
{
    (*PtrAnalogComparator_1)();
}
extern void ISR_Analogcomp2(void)
{
    (*PtrAnalogComparator_2)();
}
extern void ISR_SystemControl(void)
{
    (*PtrSystemControl)();
}
extern void ISR_FlashControl(void)
{
    (*PtrFLASHControl)();
}
extern void ISR_GPIOPPortF(void)
{
    (*PtrGPIOPortF)();
}
extern void ISR_Uart2(void)
{
    (*PtrUART2)();
}
extern void ISR_SSI1(void)
{
    (*PtrSSI1)();
}
extern void ISR_Timer3_A(void)
{
    (*PtrTimer3_SubtimerA)();
}
extern void ISR_Timer3_B(void)
{
    (*PtrTimer3_SubtimerB)();
}
extern void ISR_I2C1(void)
{
    (*PtrI2C1)();
}
extern void ISR_QuadEncoder1(void)
{
    (*PtrQuadratureEncoder_1)();
}
extern void ISR_CAN0(void)
{
    (*PtrCAN0)();
}
extern void ISR_CAN1(void)
{
    (*PtrCAN1)();
}
extern void ISR_Hibrnate(void)
{
    (*PtrHibernate)();
}
extern void ISR_USB0(void)
{
    (*PtrUSB0)();
}
extern void ISR_PWMGenereator0(void)
{
    (*PtrPWM0Generator_3)();
}
extern void ISR_uDMATrsansfer(void)
{
    (*PtruDMASoftwareTransfer)();
}
extern void ISR_uDMAEror(void)
{
    (*PtruDMAError)();
}
extern void ISR_ADC1Sequence0(void)
{
    (*PtrADC1Sequence_0)();
}
extern void ISR_ADC1Sequence1(void)
{
    (*PtrADC1Sequence_1)();
}
extern void ISR_ADC1Sequence2(void)
{
    (*PtrADC1Sequence_2)();
}
extern void ISR_ADC1Sequence3(void)
{
    (*PtrADC1Sequence_3)();
}
extern void ISR_SSI2(void)
{
        (  * PtrSSI2 ) ();

}
extern void ISR_SSI3(void)
{
    (*PtrSSI3)();
}
extern void ISR_Uart3(void)
{
    (*PtrUART3)();
}
extern void ISR_Uart4(void)
{
    (*PtrUART4)();
}
extern void ISR_Uart5(void)
{
    (*PtrUART5)();
}
extern void ISR_Uart6(void)
{
    (*PtrUART6)();
}
extern void ISR_Uart7(void)
{
    (*PtrUART7)();
}
extern void ISR_I2C2(void)
{
    (*PtrI2C2)();
}
extern void ISR_I2C3(void)
{
    (*PtrI2C3)();
}
extern void ISR_Timer4_A(void)
{
    (*PtrTimer4SubtimerA)();
}
extern void ISR_Timer4_B(void)
{
    (*PtrTimer4_SubtimerB)();
}
extern void ISR_Timer5_A(void)
{
    (*PtrTimer5_subtimerA)();
}
extern void ISR_Timer5_B(void)
{
    (*PtrTimer5_SubtimerB)();
}
extern void ISR_WTimer0_A(void)
{
    (*PtrWideTimer0_SubtimerA)();
}
extern void ISR_WTimer0_B(void)
{
    (*PtrWideTimer0_SubtimerB)();
}
extern void ISR_WTimer1_A(void)
{
    (*PtrWideTimer1_SubtimerA)();
}
extern void ISR_WTimer1_B(void)
{
    (*PtrWideTimer1_SubtimerB)();
}
extern void ISR_WTimer2_A(void)
{
    (*PtrWideTimer2_SubtimerA)();
}
extern void ISR_WTimer2_B(void)
{
    (*PtrWideTimer2_SubtimerB)();
}
extern void ISR_WTimer3_A(void)
{
    (*PtrWideTimer3_SubtimerA)();
}
extern void ISR_WTimer3_B(void)
{
    (*PtrWideTimer3_SubtimerB)();
}
extern void ISR_WTimer4_A(void)
{
    (*PtrWideTimer4_SubtimerA)();
}
extern void ISR_WTimer4_B(void)
{
    (*PtrWideTimer4_SubtimerB)();
}
extern void ISR_WTimer5_A(void)
{
    (*PtrWideTimer5_SubtimerA)();
}
extern void ISR_WTimer5_B(void)
{
    (*PtrWideTimer5_SubtimerB)();
}
extern void ISR_FPU(void)
{
    (*PtrFPU)();
}
extern void ISR_PWM1Generator0(void)
{
    (*PtrPWM1Generator_0)();
}
extern void ISR_PWM1Generator1(void)
{
    (*PtrPWM1Generator_1)();
}
extern void ISR_PWM1Generator2(void)
{
    (*PtrPWM1Generator_2)();
}
extern void ISR_PWM1Generator3(void)
{
    (*PtrPWM1Generator_3)();
}
extern void ISR_PWM1Fault(void)
{
    (*PtrPWM1Fault)();
}


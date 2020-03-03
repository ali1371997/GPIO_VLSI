/*
 * Interrupt.h
 *
 *  Created on: Mar 1 ,   2020
 *      Author: ali zewail
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_
typedef enum {
   GPIOPortA =0,  GPIOPortB ,  GPIOPortC ,  GPIOPortD ,  GPIOPortE  , UART0
 , UART1 , SSI0 , I2C0 , PWMFault , PWM0Generator_0 , PWM0Generator_1 , PWM0Generator_2
 , QuadratureEncoder_0 , ADCSequence_0 , ADCSequence_1 , ADCSequence_2
 , ADCSequence_3 , WatchdogTimer , Timer0_subtimerA , Timer0_SubtimerB
 , Timer1_SubtimerA , Timer1_SubtimerB , Timer2_SubtimerA , Timer2_SubtimerB
 , AnalogComparator_0 , AnalogComparator_1 , AnalogComparator_2 , SystemControl
 , FLASHControl , GPIOPortF , GPIOPortG , GPIOPortH , UART2 , SSI1 , Timer3_SubtimerA
 , Timer3_SubtimerB , I2C1 , QuadratureEncoder_1 , CAN0 , CAN1
 , Hibernate=43,USB0, PWM0Generator_3, uDMASoftwareTransfer, uDMAError
 , ADC1Sequence_0, ADC1Sequence_1, ADC1Sequence_2, ADC1Sequence_3
 , GPIOPortJ =54,GPIOPortK  ,GPIOPortL  ,SSI2  ,SSI3  ,UART3
 , UART4 ,UART5,UART6,UART7
 , I2C2=68,I2C3, Timer4SubtimerA, Timer4_SubtimerB
 , Timer5_subtimerA=92,Timer5_SubtimerB, WideTimer0_SubtimerA, WideTimer0_SubtimerB
 , WideTimer1_SubtimerA, WideTimer1_SubtimerB, WideTimer2_SubtimerA
 , WideTimer2_SubtimerB, WideTimer3_SubtimerA, WideTimer3_SubtimerB
 , WideTimer4_SubtimerA, WideTimer4_SubtimerB, WideTimer5_SubtimerA, WideTimer5_SubtimerB, FPU
 , PWM1Generator_0=134, PWM1Generator_1, PWM1Generator_2, PWM1Generator_3, PWM1Fault
}InterrupptID_t;

typedef enum{
    NotPending,
    Pending
}IntPending_t;

typedef enum{
    NotActive,
    Active
}IntActive_t;

void IntEnable(InterrupptID_t Int);
void IntDisable(InterrupptID_t Int);

void IntSetPending(InterrupptID_t Int);
void IntClearPending(InterrupptID_t Int);
IntPending_t IntGetPending(InterrupptID_t Int);

IntActive_t  IntGetActive(InterrupptID_t Int);

void IntSetPriority(InterrupptID_t Int,uint8 priority);
uint8 IntGetPriority(InterrupptID_t Int);

void ISRPtr(void (*ptr1)(void));

#endif /* INTERRUPT_H_ */

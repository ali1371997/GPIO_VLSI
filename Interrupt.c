#include "STD_TYPES.h"
#include "RegMap.h"
#include"Interrupt.h"

void (*ptr2)(void);

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
void ISRPtr(void (*ptr1)(void))
{
    ptr2 = ptr1;
}



/*ISR Functions*/
extern void ISR_GPIOPortA(void)
{
    (*ptr2)();
}  //GPIO Port A
extern void ISR_GPIOPortB(void)
{
    (*ptr2)();
}  //GPIO Port B
extern void ISR_GPIOPortC(void)
{
    (*ptr2)();
}  //GPIO Port C
extern void ISR_GPIOPortD(void)
{
    (*ptr2)();
}  //GPIO Port D
extern void ISR_GPIOPortE(void)
{
    (*ptr2)();
}  //GPIO Port E
extern void ISR_Uart0(void)
{
    (*ptr2)();
}  //UART0 Rx and Tx
extern void ISR_Uart1(void)
{
    (*ptr2)();
}  //UART1 Rx and Tx
extern void ISR_SSI0(void)
{
    (*ptr2)();
}  //SSI0 Rx and Tx
extern void ISR_I2C0(void)
{   (*ptr2)();}  //I2C0 Master and Slave
extern void ISR_PWM0Fault(void)
{
    (*ptr2)();
}  //PWM Fault
extern void ISR_PWM0Genretaor0(void)
{
    (*ptr2)();
}  //PWM Generator 0
extern void ISR_PWM0Genretaor1(void)
{
    (*ptr2)();
}  //PWM Generator 1
extern void ISR_PWM0Genretaor2(void)
{
    (*ptr2)();
}  //PWM Generator 2
extern void ISR_QuadEncoder0(void)
{
    (*ptr2)();
}  //Quadrature Encoder 0
extern void ISR_ADC0(void)
{
    (*ptr2)();
}  //ADC Sequence 0
extern void ISR_ADC1(void)
{
    (*ptr2)();
}  //ADC Sequence 1
extern void ISR_ADC2(void)
{
    (*ptr2)();
}  //ADC Sequence 2
extern void ISR_ADC3(void)
{
    (*ptr2)();
}  //ADC Sequence 3
extern void ISR_WatchdogTimer(void)
{
    (*ptr2)();
}  //Watchdog timer
extern void ISR_Timer0_A(void)
{
    (*ptr2)();
}  //Timer 0 subtimer A
extern void ISR_Timer0_B(void)
{
    (*ptr2)();
}  //Timer 0 subtimer B
extern void ISR_Timer1_A(void)
{
    (*ptr2)();
}  //Timer 1 subtimer A
extern void ISR_Timer1_B(void)
{
    (*ptr2)();
}  //Timer 1 subtimer B
extern void ISR_Timer2_A(void)
{
    (*ptr2)();
}  //Timer 2 subtimer A
extern void ISR_Timer2_B(void)
{
    (*ptr2)();
}  //Timer 2 subtimer B
extern void ISR_Analogcomp0(void)
{
    (*ptr2)();
}  //Analog Comparator 0
extern void ISR_Analogcomp1(void)
{
    (*ptr2)();
}  //Analog Comparator 1
extern void ISR_Analogcomp2(void)
{
    (*ptr2)();
}  //Analog Comparator 2
extern void ISR_SystemControl(void)
{
    (*ptr2)();
}  //System Control (PLL, OSC, BO)
extern void ISR_FlashControl(void)
{
    (*ptr2)();
}  //FLASH Control
extern void ISR_GPIOPPortF(void)
{
    (*ptr2)();
}  //GPIO Port F
extern void ISR_Uart2(void)
{
    (*ptr2)();
}  // UART2 Rx and Tx
extern void ISR_SSI1(void)
{
    (*ptr2)();
}  // SSI1 Rx and Tx
extern void ISR_Timer3_A(void)
{
    (*ptr2)();
}  // Timer 3 subtimer A
extern void ISR_Timer3_B(void)
{
    (*ptr2)();
}  // Timer 3 subtimer B
extern void ISR_I2C1(void)
{
    (*ptr2)();
}  // I2C1 Master and Slave
extern void ISR_QuadEncoder1(void)
{
    (*ptr2)();
}  // Quadrature Encoder 1
extern void ISR_CAN0(void)
{
    (*ptr2)();
}  // CAN0
extern void ISR_CAN1(void)
{
    (*ptr2)();
}  // CAN1
extern void ISR_Hibrnate(void)
{
    (*ptr2)();
}  // Hibernate
extern void ISR_USB0(void)
{
    (*ptr2)();
}  // USB0
extern void ISR_PWMGenereator0(void)
{
    (*ptr2)();
}  // PWM Generator 3
extern void ISR_uDMATrsansfer(void)
{
    (*ptr2)();
}  // uDMA Software Transfer
extern void ISR_uDMAEror(void)
{
    (*ptr2)();
}  // uDMA Error
extern void ISR_ADC1Sequence0(void)
{
    (*ptr2)();
}  // ADC1 Sequence 0
extern void ISR_ADC1Sequence1(void)
{
    (*ptr2)();
}  // ADC1 Sequence 1
extern void ISR_ADC1Sequence2(void)
{
    (*ptr2)();
}  // ADC1 Sequence 2
extern void ISR_ADC1Sequence3(void)
{
    (*ptr2)();
}  // ADC1 Sequence 3
extern void ISR_SSI2(void)
{
    (*ptr2)();
}  // SSI2 Rx and Tx
extern void ISR_SSI3(void)
{
    (*ptr2)();
}  // SSI3 Rx and Tx
extern void ISR_Uart3(void)
{
    (*ptr2)();
}  // UART3 Rx and Tx
extern void ISR_Uart4(void)
{
    (*ptr2)();
}  // UART4 Rx and Tx
extern void ISR_Uart5(void)
{
    (*ptr2)();
}  // UART5 Rx and Tx
extern void ISR_Uart6(void)
{
    (*ptr2)();
}  // UART6 Rx and Tx
extern void ISR_Uart7(void)
{
    (*ptr2)();
}  // UART7 Rx and Tx
extern void ISR_I2C2(void)
{
    (*ptr2)();
}  // I2C2 Master and Slave
extern void ISR_I2C3(void)
{
    (*ptr2)();
}  // I2C3 Master and Slave
extern void ISR_Timer4_A(void)
{
    (*ptr2)();
}  // Timer 4 subtimer A
extern void ISR_Timer4_B(void)
{
    (*ptr2)();
}  // Timer 4 subtimer B
extern void ISR_Timer5_A(void)
{
    (*ptr2)();
}  // Timer 5 subtimer A
extern void ISR_Timer5_B(void)
{
    (*ptr2)();
}  // Timer 5 subtimer B
extern void ISR_WTimer0_A(void)
{
    (*ptr2)();
}  // Wide Timer 0 subtimer A
extern void ISR_WTimer0_B(void)
{
    (*ptr2)();
}  // Wide Timer 0 subtimer B
extern void ISR_WTimer1_A(void)
{
    (*ptr2)();
}  // Wide Timer 1 subtimer A
extern void ISR_WTimer1_B(void)
{
    (*ptr2)();
}  // Wide Timer 1 subtimer B
extern void ISR_WTimer2_A(void)
{
    (*ptr2)();
}  // Wide Timer 2 subtimer A
extern void ISR_WTimer2_B(void)
{
    (*ptr2)();
}  // Wide Timer 2 subtimer B
extern void ISR_WTimer3_A(void)
{
    (*ptr2)();
}  // Wide Timer 3 subtimer A
extern void ISR_WTimer3_B(void)
{
    (*ptr2)();
}  // Wide Timer 3 subtimer B
extern void ISR_WTimer4_A(void)
{
    (*ptr2)();
}  // Wide Timer 4 subtimer A
extern void ISR_WTimer4_B(void)
{
    (*ptr2)();
}  // Wide Timer 4 subtimer B
extern void ISR_WTimer5_A(void)
{
    (*ptr2)();
}  // Wide Timer 5 subtimer A
extern void ISR_WTimer5_B(void)
{
    (*ptr2)();
}  // Wide Timer 5 subtimer B
extern void ISR_FPU(void)
{
    (*ptr2)();
}  // FPU
extern void ISR_I2C4(void)
{
    (*ptr2)();
}  // I2C4 Master and Slave
extern void ISR_I2C5(void)
{
    (*ptr2)();
}  // I2C5 Master and Slave
extern void ISR_QuadEncoder2(void)
{
    (*ptr2)();
}  // Quadrature Encoder 2
extern void ISR_PWM1Generator0(void)
{
    (*ptr2)();
}  // PWM 1 Generator 0
extern void ISR_PWM1Generator1(void)
{
    (*ptr2)();
}  // PWM 1 Generator 1
extern void ISR_PWM1Generator2(void)
{
    (*ptr2)();
}  // PWM 1 Generator 2
extern void ISR_PWM1Generator3(void)
{
    (*ptr2)();
}  // PWM 1 Generator 3
extern void ISR_PWM1Fault(void)
{
    (*ptr2)();
}  // PWM 1 Fault

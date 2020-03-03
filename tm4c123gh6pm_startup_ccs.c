//*****************************************************************************
//
// Startup code for use with TI's Code Composer Studio.
//
// Copyright (c) 2011-2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
//*****************************************************************************

#include <stdint.h>

//*****************************************************************************
//
// Forward declaration of the default fault handlers.
//
//*****************************************************************************
void ResetISR(void);
static void NmiSR(void);
static void FaultISR(void);
static void IntDefaultHandler(void);
//*****************************************************************************
//
// External declaration for the reset handler that is to be called when the
// processor is started
//
//*****************************************************************************
extern void _c_int00(void);

//*****************************************************************************
//
// Linker variable that marks the top of the stack.
//
//*****************************************************************************
extern uint32_t __STACK_TOP;

//*****************************************************************************
//
// External declarations for the interrupt handlers used by the application.
//
//*****************************************************************************
// To be added by user
extern void ISR_GPIOPortA(void);  //GPIO Port A
extern void ISR_GPIOPortB(void);  //GPIO Port B
extern void ISR_GPIOPortC(void);  //GPIO Port C
extern void ISR_GPIOPortD(void);  //GPIO Port D
extern void ISR_GPIOPortE(void);  //GPIO Port E
extern void ISR_Uart0(void);  //UART0 Rx and Tx
extern void ISR_Uart1(void);  //UART1 Rx and Tx
extern void ISR_SSI0(void);  //SSI0 Rx and Tx
extern void ISR_I2C0(void);  //I2C0 Master and Slave
extern void ISR_PWM0Fault(void);  //PWM Fault
extern void ISR_PWM0Genretaor0(void);  //PWM Generator 0
extern void ISR_PWM0Genretaor1(void);  //PWM Generator 1
extern void ISR_PWM0Genretaor2(void);  //PWM Generator 2
extern void ISR_QuadEncoder0(void);  //Quadrature Encoder 0
extern void ISR_ADC0(void);  //ADC Sequence 0
extern void ISR_ADC1(void);  //ADC Sequence 1
extern void ISR_ADC2(void);  //ADC Sequence 2
extern void ISR_ADC3(void);  //ADC Sequence 3
extern void ISR_WatchdogTimer(void);  //Watchdog timer
extern void ISR_Timer0_A(void);  //Timer 0 subtimer A
extern void ISR_Timer0_B(void);  //Timer 0 subtimer B
extern void ISR_Timer1_A(void);  //Timer 1 subtimer A
extern void ISR_Timer1_B(void);  //Timer 1 subtimer B
extern void ISR_Timer2_A(void);  //Timer 2 subtimer A
extern void ISR_Timer2_B(void);  //Timer 2 subtimer B
extern void ISR_Analogcomp0(void);  //Analog Comparator 0
extern void ISR_Analogcomp1(void);  //Analog Comparator 1
extern void ISR_Analogcomp2(void);  //Analog Comparator 2
extern void ISR_SystemControl(void);  //System Control (PLL, OSC, BO)
extern void ISR_FlashControl(void);  //FLASH Control
extern void ISR_GPIOPPortF(void);  //GPIO Port F
extern void ISR_Uart2(void);// UART2 Rx and Tx
extern void ISR_SSI1(void);// SSI1 Rx and Tx
extern void ISR_Timer3_A(void);// Timer 3 subtimer A
extern void ISR_Timer3_B(void);// Timer 3 subtimer B
extern void ISR_I2C1(void);// I2C1 Master and Slave
extern void ISR_QuadEncoder1(void);// Quadrature Encoder 1
extern void ISR_CAN0(void);// CAN0
extern void ISR_CAN1(void);// CAN1
extern void ISR_Hibrnate(void);// Hibernate
extern void ISR_USB0(void);// USB0
extern void ISR_PWMGenereator0(void);// PWM Generator 3
extern void ISR_uDMATrsansfer(void);// uDMA Software Transfer
extern void ISR_uDMAEror(void);// uDMA Error
extern void ISR_ADC1Sequence0(void);// ADC1 Sequence 0
extern void ISR_ADC1Sequence1(void);// ADC1 Sequence 1
extern void ISR_ADC1Sequence2(void);// ADC1 Sequence 2
extern void ISR_ADC1Sequence3(void);// ADC1 Sequence 3
extern void ISR_SSI2(void);// SSI2 Rx and Tx
extern void ISR_SSI3(void);// SSI3 Rx and Tx
extern void ISR_Uart3(void);// UART3 Rx and Tx
extern void ISR_Uart4(void);// UART4 Rx and Tx
extern void ISR_Uart5(void);// UART5 Rx and Tx
extern void ISR_Uart6(void);// UART6 Rx and Tx
extern void ISR_Uart7(void);// UART7 Rx and Tx
extern void ISR_I2C2(void);// I2C2 Master and Slave
extern void ISR_I2C3(void);// I2C3 Master and Slave
extern void ISR_Timer4_A(void);// Timer 4 subtimer A
extern void ISR_Timer4_B(void);// Timer 4 subtimer B
extern void ISR_Timer5_A(void);// Timer 5 subtimer A
extern void ISR_Timer5_B(void);// Timer 5 subtimer B
extern void ISR_WTimer0_A(void);// Wide Timer 0 subtimer A
extern void ISR_WTimer0_B(void);// Wide Timer 0 subtimer B
extern void ISR_WTimer1_A(void);// Wide Timer 1 subtimer A
extern void ISR_WTimer1_B(void);// Wide Timer 1 subtimer B
extern void ISR_WTimer2_A(void);// Wide Timer 2 subtimer A
extern void ISR_WTimer2_B(void);// Wide Timer 2 subtimer B
extern void ISR_WTimer3_A(void);// Wide Timer 3 subtimer A
extern void ISR_WTimer3_B(void);// Wide Timer 3 subtimer B
extern void ISR_WTimer4_A(void);// Wide Timer 4 subtimer A
extern void ISR_WTimer4_B(void);// Wide Timer 4 subtimer B
extern void ISR_WTimer5_A(void);// Wide Timer 5 subtimer A
extern void ISR_WTimer5_B(void);// Wide Timer 5 subtimer B
extern void ISR_FPU(void);// FPU
extern void ISR_I2C4(void);// I2C4 Master and Slave
extern void ISR_I2C5(void);// I2C5 Master and Slave
extern void ISR_QuadEncoder2(void);// Quadrature Encoder 2
extern void ISR_PWM1Generator0(void);// PWM 1 Generator 0
extern void ISR_PWM1Generator1(void);// PWM 1 Generator 1
extern void ISR_PWM1Generator2(void);// PWM 1 Generator 2
extern void ISR_PWM1Generator3(void);// PWM 1 Generator 3
extern void ISR_PWM1Fault(void);// PWM 1 Fault



//*****************************************************************************
//
// The vector table.  Note that the proper constructs must be placed on this to
// ensure that it ends up at physical address 0x0000.0000 or at the start of
// the program if located at a start address other than 0.
//
//*****************************************************************************
#pragma DATA_SECTION(g_pfnVectors, ".intvecs")
void (* const g_pfnVectors[])(void) =
{
    (void (*)(void))((uint32_t)&__STACK_TOP),
                                            // The initial stack pointer
    ResetISR,                               // The reset handler
    NmiSR,                                  // The NMI handler
    FaultISR,                               // The hard fault handler
    IntDefaultHandler,                      // The MPU fault handler
    IntDefaultHandler,                      // The bus fault handler
    IntDefaultHandler,                      // The usage fault handler
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    IntDefaultHandler,                      // SVCall handler
    IntDefaultHandler,                      // Debug monitor handler
    0,                                      // Reserved
    IntDefaultHandler,                      // The PendSV handler
    IntDefaultHandler,                      // The SysTick handler
    ISR_GPIOPortA,                      // GPIO Port A
    ISR_GPIOPortB,                      // GPIO Port B
    ISR_GPIOPortC,                      // GPIO Port C
    ISR_GPIOPortD,                      // GPIO Port D
    ISR_GPIOPortE,                      // GPIO Port E
    ISR_Uart0,                      // UART0 Rx and Tx
    ISR_Uart1,                      // UART1 Rx and Tx
    ISR_SSI0,                      // SSI0 Rx and Tx
    ISR_I2C0,                      // I2C0 Master and Slave
    ISR_PWM0Fault,                      // PWM Fault
    ISR_PWM0Genretaor0,                      // PWM Generator 0
    ISR_PWM0Genretaor1,                      // PWM Generator 1
    ISR_PWM0Genretaor2,                      // PWM Generator 2
    ISR_QuadEncoder0,                      // Quadrature Encoder 0
    ISR_ADC0,                      // ADC Sequence 0
    ISR_ADC1,                      // ADC Sequence 1
    ISR_ADC2,                      // ADC Sequence 2
    ISR_ADC3,                      // ADC Sequence 3
    ISR_WatchdogTimer,                      // Watchdog timer
    ISR_Timer0_A,                      // Timer 0 subtimer A
    ISR_Timer0_B,                      // Timer 0 subtimer B
    ISR_Timer1_A,                             // Timer 1 subtimer A
    ISR_Timer1_B,                      // Timer 1 subtimer B
    ISR_Timer2_A,                      // Timer 2 subtimer A
    ISR_Timer2_B,                      // Timer 2 subtimer B
    ISR_Analogcomp0,                      // Analog Comparator 0
    ISR_Analogcomp1,                      // Analog Comparator 1
    ISR_Analogcomp2,                      // Analog Comparator 2
    ISR_SystemControl,                      // System Control (PLL, OSC, BO)
    ISR_FlashControl,                      // FLASH Control
    ISR_GPIOPPortF,                      // GPIO Port F
    IntDefaultHandler,                      // GPIO Port G
    IntDefaultHandler,                      // GPIO Port H
    ISR_Uart2,                      // UART2 Rx and Tx
    ISR_SSI1,                      // SSI1 Rx and Tx
    ISR_Timer3_A,                      // Timer 3 subtimer A
    ISR_Timer3_B,                      // Timer 3 subtimer B
    ISR_I2C1,                      // I2C1 Master and Slave
    ISR_QuadEncoder1,                      // Quadrature Encoder 1
    ISR_CAN0,                      // CAN0
    ISR_CAN1,                      // CAN1
    0,                                      // Reserved
    0,                                      // Reserved
    ISR_Hibrnate,                      // Hibernate
    ISR_USB0,                           // USB0
    ISR_PWMGenereator0,                      // PWM Generator 3
    ISR_uDMATrsansfer,                      // uDMA Software Transfer
    ISR_uDMAEror,                      // uDMA Error
    ISR_ADC1Sequence0,                      // ADC1 Sequence 0
    ISR_ADC1Sequence1,                      // ADC1 Sequence 1
    ISR_ADC1Sequence2,                      // ADC1 Sequence 2
    ISR_ADC1Sequence3,                      // ADC1 Sequence 3
    0,                                      // Reserved
    0,                                      // Reserved
    IntDefaultHandler,                      // GPIO Port J
    IntDefaultHandler,                      // GPIO Port K
    IntDefaultHandler,                      // GPIO Port L
    ISR_SSI2,                      // SSI2 Rx and Tx
    ISR_SSI3,                      // SSI3 Rx and Tx
    ISR_Uart3,                      // UART3 Rx and Tx
    ISR_Uart4,                      // UART4 Rx and Tx
    ISR_Uart5,                      // UART5 Rx and Tx
    ISR_Uart6,                      // UART6 Rx and Tx
    ISR_Uart7,                      // UART7 Rx and Tx
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    ISR_I2C2,                      // I2C2 Master and Slave
    ISR_I2C3,                      // I2C3 Master and Slave
    ISR_Timer4_A,                      // Timer 4 subtimer A
    ISR_Timer4_B,                      // Timer 4 subtimer B
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    ISR_Timer5_A,                      // Timer 5 subtimer A
    ISR_Timer5_B,                      // Timer 5 subtimer B
    ISR_WTimer0_A,                      // Wide Timer 0 subtimer A
    ISR_WTimer0_B,                      // Wide Timer 0 subtimer B
    ISR_WTimer1_A,                      // Wide Timer 1 subtimer A
    ISR_WTimer1_B,                      // Wide Timer 1 subtimer B
    ISR_WTimer2_A,                      // Wide Timer 2 subtimer A
    ISR_WTimer2_B,                      // Wide Timer 2 subtimer B
    ISR_WTimer3_A,                      // Wide Timer 3 subtimer A
    ISR_WTimer3_B,                      // Wide Timer 3 subtimer B
    ISR_WTimer4_A,                      // Wide Timer 4 subtimer A
    ISR_WTimer4_B,                      // Wide Timer 4 subtimer B
    ISR_WTimer5_A,                      // Wide Timer 5 subtimer A
    ISR_WTimer5_B,                      // Wide Timer 5 subtimer B
    ISR_FPU,                      // FPU
    0,                                      // Reserved
    0,                                      // Reserved
    ISR_I2C4,                      // I2C4 Master and Slave
    ISR_I2C5,                      // I2C5 Master and Slave
    IntDefaultHandler,                      // GPIO Port M
    IntDefaultHandler,                      // GPIO Port N
    ISR_QuadEncoder2,                      // Quadrature Encoder 2
    0,                                      // Reserved
    0,                                      // Reserved
    IntDefaultHandler,                      // GPIO Port P (Summary or P0)
    IntDefaultHandler,                      // GPIO Port P1
    IntDefaultHandler,                      // GPIO Port P2
    IntDefaultHandler,                      // GPIO Port P3
    IntDefaultHandler,                      // GPIO Port P4
    IntDefaultHandler,                      // GPIO Port P5
    IntDefaultHandler,                      // GPIO Port P6
    IntDefaultHandler,                      // GPIO Port P7
    IntDefaultHandler,                      // GPIO Port Q (Summary or Q0)
    IntDefaultHandler,                      // GPIO Port Q1
    IntDefaultHandler,                      // GPIO Port Q2
    IntDefaultHandler,                      // GPIO Port Q3
    IntDefaultHandler,                      // GPIO Port Q4
    IntDefaultHandler,                      // GPIO Port Q5
    IntDefaultHandler,                      // GPIO Port Q6
    IntDefaultHandler,                      // GPIO Port Q7
    IntDefaultHandler,                      // GPIO Port R
    IntDefaultHandler,                      // GPIO Port S
    ISR_PWM1Generator0,                      // PWM 1 Generator 0
    ISR_PWM1Generator1,                      // PWM 1 Generator 1
    ISR_PWM1Generator2,                      // PWM 1 Generator 2
    ISR_PWM1Generator3,                      // PWM 1 Generator 3
    ISR_PWM1Fault                       // PWM 1 Fault
};

//*****************************************************************************
//
// This is the code that gets called when the processor first starts execution
// following a reset event.  Only the absolutely necessary set is performed,
// after which the application supplied entry() routine is called.  Any fancy
// actions (such as making decisions based on the reset cause register, and
// resetting the bits in that register) are left solely in the hands of the
// application.
//
//*****************************************************************************
void
ResetISR(void)
{
    //
    // Jump to the CCS C initialization routine.  This will enable the
    // floating-point unit as well, so that does not need to be done here.
    //
    __asm("    .global _c_int00\n"
          "    b.w     _c_int00");
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a NMI.  This
// simply enters an infinite loop, preserving the system state for examination
// by a debugger.
//
//*****************************************************************************
static void
NmiSR(void)
{
    //
    // Enter an infinite loop.
    //
    while(1)
    {
    }
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives a fault
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
static void
FaultISR(void)
{
    //
    // Enter an infinite loop.
    //
    while(1)
    {
    }
}

//*****************************************************************************
//
// This is the code that gets called when the processor receives an unexpected
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
static void
IntDefaultHandler(void)
{
    //
    // Go into an infinite loop.
    //
    while(1)
    {
    }
}

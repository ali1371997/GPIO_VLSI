/**
 * main.c
 */
#include"STD_TYPES.h"
#include "Utils.h"
#include "GPIO.h"
#include "Interrupt.h"

void IntPortF(void);

void _delay_ms(uint32 n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < 3180; j++)
        {
        } /* do nothing for 1 ms */
}

int main(void)
{
    GPIOBusSet(PORTF, AHB);
    GPIOClockSet(PORTF);
    GPIODirModeSet(PORTF_AHB, 0b00000010, MODE_OUT);
    GPIODirModeSet(PORTF_AHB, 0b00010000, MODE_IN);
    GPIOPadSet(PORTF_AHB, 0b00010000, Drive_4mA, Pad_PU);
    GPIOInterruptModeSet(PORTF_AHB, 0b00010000, FallingEdge);
    GPIOInterruptEnable(PORTF_AHB, 0b00010000);
    GPIOInterruptClearFlag(PORTF_AHB, 0b00010000);

    ISRPtr(IntPortF);
    IntSetPriority(GPIOPortF, 7);
    IntEnable(GPIOPortF);

    while (1)
    {
        GPIOWrite(PORTF_AHB, 0b00000010, 0xff);

    }

    return 0;
}

void IntPortF(void)
{
    GPIOWrite(PORTF_AHB, 0b00000010, 0x00);
    _delay_ms(1000);
    GPIOInterruptClearFlag(PORTF_AHB, 0b00010000);

}

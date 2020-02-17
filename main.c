/**
 * main.c
 */
#include"RegMap.h"
#include"STD_TYPES.h"
#include"GPIO.h"

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
    gpio_bus_t bus;

    GPIOBusSet(PORTF, AHB);
    GPIOClockSet(PORTF);
    GPIODirModeSet(PORTF_AHB, 0b00001110, MODE_OUT);
    bus = GPIOBusGet(PORTF);
    while (1)
    {
        GPIOWrite(PORTF_AHB, 0b00001110, 0b00000010);
        _delay_ms(1000);
        GPIOWrite(PORTF_AHB, 0b00001110, 0b00000100);
        _delay_ms(1000);
        GPIOWrite(PORTF_AHB, 0b00001110, 0b00001000);
        _delay_ms(1000);

    }
    return 0;
}

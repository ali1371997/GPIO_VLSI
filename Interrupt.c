#include "STD_TYPES.h"
#include "RegMap.h"
#include"Interrupt.h"

extern void (*g_pfnVectors[])(void);
#pragma DATA_ALIGN(g_pfnRAMVectors, 1024)
void (*g_pfnRAMVectors[155])(void);

void IntEnable(InterrupptID_t Int)
{

    (*((volatile uint32*) (((Int / 32) * 4) + Int_EN))) |= (1 << (Int % 32));

}

void IntDisable(InterrupptID_t Int)
{

    (*((volatile uint32*) (((Int / 32) * 4) + Int_DIS))) |= (1 << (Int % 32));

}

void IntSetPending(InterrupptID_t Int)
{

    (*((volatile uint32*) (((Int / 32) * 4) + Int_PEND))) |= (1 << (Int % 32));

}
void IntClearPending(InterrupptID_t Int)
{

    (*((volatile uint32*) (((Int / 32) * 4) + Int_UNPEND))) |=
            (1 << (Int % 32));

}
IntPending_t IntGetPending(InterrupptID_t Int)
{
    uint32 pend;
    uint8 shift = Int % 32;

    pend = (*((volatile uint32*) (((Int / 32) * 4) + Int_PEND)));
    pend &= (1 << shift);
    pend = (pend >> shift);
    return pend;
}

IntActive_t IntGetActive(InterrupptID_t Int)
{
    uint32 active;
    uint8 shift = Int % 32;

    active = (*((volatile uint32*) (((Int / 32) * 4) + Int_ACTIVE)));
    active &= (1 << shift);
    active = (active >> shift);

    return active;

}

void IntSetPriority(InterrupptID_t Int, uint8 priority)
{
    uint8 shift = Int % 4;

    (*((volatile uint32*) (((Int / 32) * 4) + Int_PRI))) |= (priority
            << ((shift * 8) + 5));

}

uint8 IntGetPriority(InterrupptID_t Int)
{
    uint8 shift = Int % 4;
    uint32 priority = 0;

    priority = (*((volatile uint32*) (((Int / 32) * 4) + Int_PRI)));
    priority &= (1 << ((shift * 8) + 5));
    priority = (priority >> ((shift * 8) + 5));
    return priority;
}

/*callback function to choose which funtion to  be handeled when interrupt happens*/

/*ISRRegister Function*/

void IntRegister(void (*ptr1)(void), InterrupptID_t Int)
{

    uint8 i = 0;
    for (i = 0; i < 155; i++)
    {

        g_pfnRAMVectors[i] = g_pfnVectors[i];
    }

    (*((volatile uint32*) ( Int_VTable))) = g_pfnRAMVectors;

    g_pfnRAMVectors[Int + 16] = *ptr1;
}


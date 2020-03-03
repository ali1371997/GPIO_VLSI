#include"STD_TYPES.h"
#include"RegMap.h"
#include "GPIO.h"

void GPIODirModeSet(gpio_port_t port, uint8 pins, gpio_mode_t Mode)
{

    /*alternative fn.*/
    uint8 data = (*((volatile uint32 *) (port + GPIOAFSEL)));

    data &= ~(pins);
    if (Mode == MODE_AF)
    {
        data |= (0xff & pins);
    }
    else
    {
        data |= (0x00 & pins);
    }
    (*((volatile uint32 *) (port + GPIOAFSEL))) = data;

    /*direction*/
    data = (*((volatile uint32 *) (port + GPIODIR)));
    data &= ~(pins);
    data |= (Mode & pins);
    (*((volatile uint32 *) (port + GPIODIR))) = data;

    /* digital enable*/
    data = (*((volatile uint32 *) (port + GPIODEN)));
    data &= ~(pins);
    data |= (0XFF & pins);
    (*((volatile uint32 *) (port + GPIODEN))) = data;

}

uint8 GPIODirGet(gpio_port_t port, uint8 pins)
{
    uint8 data = (*((volatile uint32 *) (port + GPIODIR)));
    data &= pins;

    return data;
}

uint8 GPIOModeGet(gpio_port_t port, uint8 pins)
{

    uint8 data = (*((volatile uint32 *) (port + GPIOAFSEL)));
    data &= pins;

    return data;

}

void GPIOBusSet(gpio_port_CTL_t port, gpio_bus_t bus)
{/*   uint32 Shift=port-(0x40058000);
 Shift=Shift/4000;
 */
    GPIO_HBCTL |= (bus << port);
}

gpio_bus_t GPIOBusGet(gpio_port_CTL_t port)
{
    gpio_bus_t bus;
    bus = ((GPIO_HBCTL & (1 << port)) >> port);
    return bus;
}

void GPIOClockSet(gpio_port_CTL_t port)
{

    GPIO_RCGC |= (1 << port);
}

void GPIOClockRst(gpio_port_CTL_t port)
{
    GPIO_RCGC &= (0 << port);
}

uint8 GPIOClockGet(gpio_port_CTL_t port)
{
    uint8 clock;
    clock = (GPIO_RCGC >> port);
    return clock;
}

void GPIOPadSet(gpio_port_t port, uint8 pins, gpio_drive_t str, gpio_pad_t pad)
{
    /*pad select*/
    uint8 data = (*((volatile uint32 *) (port + pad)));
    data |= (0xff & pins);
    (*((volatile uint32 *) (port + pad))) = data;

    /*current strength select*/
    data = (*((volatile uint32 *) (port + str)));
    data |= (0xff & pins);
    (*((volatile uint32 *) (port + str))) = data;
    if (str == Drive_8mA_Selw)
    {
        data = (*((volatile uint32 *) (port + GPIOSLR)));
        data |= (0xff & pins);
        (*((volatile uint32 *) (port + str))) = data;
    }
}

uint8 GPIOPadDrive2_mAGet(gpio_port_t port, uint8 pins)
{
    uint8 data = (*((volatile uint32 *) (port + Drive_2mA)));
    data &= pins;
    return data;
}

<<<<<<< HEAD
uint8 GPIOPadDrive4_mAGet(gpio_port_t port, uint8 pins)
{
=======



uint8 GPIOPadDrive2_mAGet(gpio_port_t port, uint8 pins)
{
    uint8 data = (*((volatile uint32 *) (port + Drive_2mA)));
    data &= pins;
    return data;
}


uint8 GPIOPadDrive4_mAGet(gpio_port_t port, uint8 pins){
>>>>>>> 1bfb1b1ddaf559cc7f3ec5d4a28c6b84eb432089
    uint8 data = (*((volatile uint32 *) (port + Drive_4mA)));
    data &= pins;
    return data;

}

<<<<<<< HEAD
uint8 GPIOPadDrive8_mAGet(gpio_port_t port, uint8 pins)
=======

uint8 GPIOPadDrive8_mAGet(gpio_port_t port, uint8 pins){
    uint8 data = (*((volatile uint32 *) (port + Drive_8mA)));
    data &= pins;
    return data;

}

uint8 GPIOPadOpenDrainGet(gpio_port_t port, uint8 pins)
>>>>>>> 1bfb1b1ddaf559cc7f3ec5d4a28c6b84eb432089
{
    uint8 data = (*((volatile uint32 *) (port + Drive_8mA)));
    data &= pins;
    return data;

}

uint8 GPIOPadOpenDrainGet(gpio_port_t port, uint8 pins)
{
    uint8 data = (*((volatile uint32 *) (port + GPIOODR)));
    data &= pins;
    return data;

}

uint8 GPIOPadPullUpGet(gpio_port_t port, uint8 pins)
{
    uint8 data = (*((volatile uint32 *) (port + GPIOPUR)));
    data &= pins;
    return data;
}

uint8 GPIOPadPullDownGet(gpio_port_t port, uint8 pins)
{

    uint8 data = (*((volatile uint32 *) (port + GPIOPDR)));
    data &= pins;
    return data;

}

uint8 GPIORead(gpio_port_t port, uint8 pins)

{

    uint8 data = (*((volatile uint32 *) (port + (pins << 2))));
    return data;

}

void GPIOWrite(gpio_port_t port, uint8 pins, uint8 data)

{
    (*((volatile uint32 *) (port + (pins << 2)))) = data;

}

void GPIOInterruptModeSet(gpio_port_t port, uint8 pins,
                          GPIO_InterruptMode_t mode)
{

    uint8 IS = (*((volatile uint32 *) (port + GPIOIS)));
    uint8 IBE = (*((volatile uint32 *) (port + GPIOIBE)));
    uint8 IEV = (*((volatile uint32 *) (port + GPIOIEV)));

    switch (mode)
    {
    case LowLevel:
        IS |= (pins & 0xff);
        IBE &= (pins & 0x00);
        IEV &= (~pins);
        break;
    case HighLevel:
        IS |= (pins & 0xff);
        IBE &= (pins & 0x00);
        IEV |= (pins & 0xff);
        break;

    case FallingEdge:
        IS &= (~pins);
        IBE &= (pins & 0x00);
        IEV &= (~pins);
        break;
    case RisingEdge:
        IS &= (~pins);
        IBE &= (pins & 0x00);
        IEV |= (pins & 0xff);
        break;
    case BothEdges:
        IS &= (~pins);
        IBE |= (pins & 0xff);
        break;

    }
    (*((volatile uint32 *) (port + GPIOIS))) = IS;
    (*((volatile uint32 *) (port + GPIOIBE))) = IBE;
    (*((volatile uint32 *) (port + GPIOIEV))) = IEV;

}


void GPIOInterruptEnable(gpio_port_t port, uint8 pins){
    uint8 data = (*((volatile uint32 *) (port + GPIOIM)));
    data|=(pins&0xff);
    (*((volatile uint32 *) (port + GPIOIM)))=data;
}



void GPIOInterruptDisable(gpio_port_t port, uint8 pins){
    uint8 data = (*((volatile uint32 *) (port + GPIOIM)));
    data&=(~pins);
    (*((volatile uint32 *) (port + GPIOIM)))=data;
}

void GPIOInterruptClearFlag(gpio_port_t port, uint8 pins){
    uint8 data = (*((volatile uint32 *) (port + GPIOICR)));
    data|=(pins&0xff);
    (*((volatile uint32 *) (port + GPIOICR)))=data;

}

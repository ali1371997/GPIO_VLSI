/*
 * RegMap.h
 *
 *  Created on: Feb 17, 2020
 *      Author: ali zewail
 */

#ifndef REGMAP_H_
#define REGMAP_H_

#define GPIO_RCGC (*((volatile uint32*)0x400FE608))

#define GPIO_HBCTL (*((volatile uint32*)0x400FE06C))

/*
 #define     PORTA_AHB       0x40058000
 #define     PORTA_APB       0x40004000

 #define     PORTB_AHB       0x40059000
 #define     PORTB_APB       0x40005000

 #define     PORTC_AHB       0x4005A000
 #define     PORTC_APB       0x40006000

 #define     PORTD_AHB       0x4005B000
 #define     PORTD_APB       0x40007000

 #define     PORTE_AHB       0x4005C000
 #define     PORTE_APB       0x40024000

 #define     PORTF_APB       0x40025000
 #define     PORTF_AHB       0x4005D000
 */

#define     GPIODATA        0x000
#define     GPIODIR         0x400
#define     GPIOAFSEL       0x420
#define     GPIODR2R        0x500
#define     GPIODR4R        0x504
#define     GPIODR8R        0x508
#define     GPIOODR         0x50C
#define     GPIOPUR         0x510
#define     GPIOPDR         0x514
#define     GPIOSLR         0x518
#define     GPIODEN         0x51C
#define     GPIOIS          0x404
#define     GPIOIBE         0x408
#define     GPIOIEV         0x40C
#define     GPIOIM          0x410
#define     GPIOICR         0x41C

/*Interrupts*/
#define Int_EN 0xE000E100
#define Int_DIS 0xE000E180

#define Int_PEND 0xE000E200
#define Int_UNPEND 0xE000E280
#define Int_ACTIVE 0xE000E300
#define Int_PRI 0xE000E400
#define Int_VTable 0xE000ED08


#endif /* REGMAP_H_ */

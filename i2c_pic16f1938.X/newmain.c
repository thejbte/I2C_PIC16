/*
 * File:   newmain.c
 * Author: Julian
 *
 * Created on 19 de abril de 2020, 03:08 PM
 */

// PIC16F1938 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#pragma warning push
#pragma warning disable 520   /*unused functions disbaled warning*/
#pragma warning pop

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "i2c.h"
#include "TC74.h"
#include "uart.h"
#include "gpio.h"
#define _XTAL_FREQ 16000000

TC74Data_t TC74Data;

void main(void) {
    OSCILLATOR_Initialize();
    PIN_MANAGER_Initialize();
    EUSART_Initialize();

    I2C_Initialize();  /*!< initialize I2C library*/
    TC74_Initialize(&TC74Data,ADDR_A5,Wrappers_I2CMaster_Write,Wrappers_I2CMaster_Read);/*Initialize TC74*/
    while (1){  
       __delay_ms (100); 
       printf("Temperature %d C\r\n", TC74_Temperature(&TC74Data)); /*uart redirect to printf with function putch*/
    }

    return;
}

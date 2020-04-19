/* 
 * File:   uart.h
 * Author: Julian
 *
 * Created on 19 de abril de 2020, 04:45 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
void EUSART_Initialize(void);
void EUSART_Write(uint8_t txData);
/*uart redirect to printf with function putch*/
void putch(char txData);

uint8_t EUSART_Read(void);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */


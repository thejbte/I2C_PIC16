#include "uart.h"

#include <xc.h>

void EUSART_Initialize(void)
{
    // Set the EUSART module to the options selected in the user interface.

    // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUDCON = 0x08;

    // SPEN enabled; RX9 8-bit; CREN disabled; ADDEN disabled; SREN disabled; 
    RCSTA = 0x80;

    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TXSTA = 0x24;

    // SPBRGL 160;    416-9600
    SPBRGL = 0xA0;

    // SPBRGH 1; 
    SPBRGH = 0x01;
}
void EUSART_Write(uint8_t txData)
{
    while(0 == PIR1bits.TXIF)  /*NO SE DISPARA LA INTERRUPT PERO SI LA BANDERA O HACERLO CON TMRT*/
    {
    }

    TXREG = txData;    // Write the data byte to the USART.
}

/*uart redirect to printf with function putch*/
void putch(char txData)
{
    EUSART_Write(txData);
}

uint8_t EUSART_Read(void)
{
    while(!PIR1bits.RCIF)
    {
    }

    
    if(1 == RCSTAbits.OERR)
    {
        // EUSART error - restart

        RCSTAbits.CREN = 0; 
        RCSTAbits.CREN = 1; 
    }

    return RCREG;
}

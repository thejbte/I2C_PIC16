#include "gpio.h"
#include <xc.h>
void OSCILLATOR_Initialize(void)
{
    // SCS CONNFIGURATIONS WORD; SPLLEN disabled; IRCF 16MHz_HF; 
    OSCCON = 0x78;//7A  // SCS INTOSC
    // TUN 0; 
    OSCTUNE = 0x00;
    // SBOREN disabled; 
    BORCON = 0x00;
}
void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x0F;
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0xBF;


    /**
    ANSELx registers
    */
    ANSELB = 0x3F;
    ANSELA = 0x3F;

    /**
    WPUx registers
    */
    WPUE = 0x00;
    WPUB = 0x00;
    OPTION_REGbits.nWPUEN = 1;


    /**
    APFCONx registers
    */
    APFCON = 0x00; 
}

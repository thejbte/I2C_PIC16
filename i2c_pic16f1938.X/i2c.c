/* 
 * File:   i2c.h
 * Author: Esp.Ing.Julian Bustamante N
 *
 * Created on April 14, 2020, 5:39 PM
 */

#include "i2c.h"
#include <xc.h>

/**ver secuencia de master transmission y master reception, a medida que se construye cada función se navega entre tx y rx para saber como completar las funciones
 * ver la nota 1 de sspstat, por eso se debe garantizar primero que no este en progreso la transmisión y ahí si se escribe start,stop,acken...
 * para una comunicación con un dispositivo i2c  slave se debe tener en cuenta la secuencia que dice el datasheet para leer ,escribir, cuando enviar el ack o nack. etc
 * Si la comunicación es entre dos micros uno debe ser esclavo y otro slave sspcon
 * multi slave averiguar
 *  */

/*Master write
 * Master : START | ADDR+W |     | DATA |     | DATA |     | ... | DATA |     | STOP
 * Slave  :       |        | ACK |      | ACK |      | ACK | ... |      | ACK |
 */


/**
 * Master read example
Master : START | ADDR+R |     |      | ACK |      | ACK | ... |      | NACK | STOP
Slave  :       |        | ACK | DATA |     | DATA |     | ... | DATA |      |
 */
void I2C_Initialize(void){
/* initialize pins*/
    SDA_DIR = 1;    /*make pin sda y scl */
    SCL_DIR = 1;

    SSPCON1 = 0B00101000 ; /* I2C Master mode, */
    SSPADD = (unsigned char)((_XTAL_FREQ/4000/I2C_SPEED)-1); /*!<  clock = FOSC / (4 * (SSPADD+1)) SSPADD values of 0, 1 or 2 are not supported for I2C Mode 0X27 -> 100KHZ*/
   // SSPADD = (_XTAL_FREQ/(4*100000))-1; 
    SSPCON2 = 0x00;
    SSPSTAT =0x00;
}
/** function which is used to hold the execution of the device until the current I2C operation is completed. */
/**asegurando de que el 2º bit en SSPSTAT sea cero Transmit is not in progress y, de manera similar, los bits del 0 al 4 sean cero en SSPCON2 .*/
void I2C_Wait1(void){
    /** is not used interrupt sspif*/
    while( (SSPSTAT & 0x04) || (SSPCON2 & 0b00011111)) ; /*si los bits son 1, espera que termine y sigue*/
}
void I2C_Wait2(void){
    /** is not used interrupt sspif*/
    while(!PIR1bits.SSPIF);     /*Wait for it to complete*/
    PIR1bits.SSPIF = 0;         /*CLear the flag bit*/
}

void I2C_Start(void){
    I2C_WAIT_FCN();
    SSPCON2bits.SEN = 1;        /*Start condition*/

}
void I2C_RStart(void){
    I2C_WAIT_FCN();
    SSPCON2bits.RSEN = 1;        /*RepeatedStart condition*/

}

void I2C_Stop(void){
    I2C_WAIT_FCN(); /*debe estar inactivo deben ir antes para garantizar que este libre todo y si se mande el stop*/
    SSPCON2bits.PEN = 1;        /*Stop condition*/

}

void I2C_Send_ACK(void){
    I2C_WAIT_FCN();
    SSPCON2bits.ACKEN = 1 ; /*Initiate Acknowledge sequence on SDA and SCL pins, and transmit ACKDT data bit.
Automatically cleared by hardware.*/


}

int I2C_Write(unsigned char data){
    I2C_WAIT_FCN();
    SSPBUF = data;        /*Write data to i2c*/

    /**return ackstat????*/
    return SSPCON2bits.ACKSTAT;
}

unsigned char  I2C_Read(int ack){
    int tempbuf;
    I2C_WAIT_FCN();
    SSPCON2bits.RCEN = 1;   /*Enable reception*/
    I2C_WAIT_FCN();
    tempbuf =SSPBUF;
    I2C_WAIT_FCN();
    ACKDT =ack; // 0-- not ACK , 1-- ACK
    I2C_Send_ACK();// Send Acknowledgement
    return tempbuf;  /*Return received data */
}

/*Funciones a modificar dependiendo de la aplicación, se pasan al driver o se usan manualmente*/
/** Envia 2 bytes registro y dato a escribir*/
void Wrappers_I2CMaster_Write(uint8_t Address7b, void * data, uint8_t amount){
    uint8_t *DatatoSend = (uint8_t *)data;
    I2C_Start ();
    I2C_Write (Address7b<<1);// slave address + write
    I2C_Write (DatatoSend[0]);// slave address register to write
    I2C_Write (DatatoSend[1]);//writing into register addr config
    I2C_Stop ();
}

void Wrappers_I2CMaster_Read(uint8_t Address7b, void * Register, uint8_t amount){

    
uint8_t *DatatoSend = (uint8_t *)Register; /* El dato leido lo almaceno en el buffer o en el mismo registro*/
    I2C_Start ();
    I2C_Write (Address7b<<1);// slave address + write
     //ack slave
     I2C_Write (*DatatoSend);//writing into register addr temp
     //ack slave
     I2C_RStart(); // repeated start
     I2C_Write (Address7b<<1|0x01); //slave address + read
    //ack slave
    /* El dato leido lo almaceno en el buffer o en el mismo registro*/
    *DatatoSend = I2C_Read (1);//nack
    I2C_Stop ();
}
/* 
 * File:   i2c.h
 * Author: Esp.Ing.Julian Bustamante N
 * @brief : I2c pic
 * Created on April 14, 2020, 5:39 PM
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "i2c.h"
#include "mcc_generated_files/mcc.h"
    
#define I2C_SPEED           100         /*!< KHZ*/
#define SDA_PIN             RC4     /*!< Data in i2c*/
#define SCL_PIN             RC3     /*!< Clock in i2c*/  
#define SDA_DIR             TRISC4  /*!< Data in i2c*/
#define SCL_DIR             TRISC3  /*!< Clock in i2c*/ 

#define I2C_WAIT_FCN()     I2C_Wait1()// I2C_Wait2()
 /*22.6.6 datasheet sequence transmit master*/   
void I2C_Initialize(void);
void I2C_Wait1(void);
void I2C_Wait2(void);
void I2C_Start(void);
void I2C_RStart(void);
void I2C_Stop(void);
int I2C_Write(unsigned char data);
unsigned char  I2C_Read(int ack);
void I2C_Send_ACK(void);

void Wrappers_I2CMaster_Write(uint8_t Address, void * data, uint8_t amount);

void Wrappers_I2CMaster_Read(uint8_t Address, void * Register, uint8_t amount);


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */


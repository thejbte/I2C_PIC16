
/*   Device            :  PIC16F1937*/
#include "mcc_generated_files/mcc.h"
#include "i2c.h"
#include <stdio.h>
#include <stdint.h>
#include "TC74.h"

#pragma warning push
#pragma warning disable 520   /*unused functions disbaled warning*/
#pragma warning pop

TC74Data_t TC74Data;

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    I2C_Initialize();  /*!< initialize I2C library*/
    TC74_Initialize(&TC74Data,ADDR_A5,Wrappers_I2CMaster_Write,Wrappers_I2CMaster_Read);/*Initialize TC74*/
   
    while (1){  
       __delay_ms (100); 
         printf("Temperature %d\r\n", TC74_Temperature(&TC74Data));
    }
}


/**
 End of File
*/






      /* MAnual sin funciones ni driver 
       * 
       * printf("hola mundo %d\r\n",x);
       //--------------------tc74--------------------------- 
         I2C_Start ();
         I2C_Write (0x4D<<1);// slave address + write
         //ack slave
         I2C_Write (0x00);//writing into register addr temp
         //ack slave
         I2C_RStart(); // repeated start
          I2C_Write (0x4D<<1|0x01); //slave address + read
          //ack slave
          x = I2C_Read (1);//nack
          I2C_Stop ();
          printf("hola mundo %d\r\n",x);*/


/*
      * //--------------------24AA00 EEPROM memory---------------------------
        I2C_Start ();  // start I2C
        I2C_Write (0xA0); // using 24aa00 slave address
        I2C_Write (0x01);  // writing into register 0x01
        I2C_Write ('f');  // write data
        I2C_Stop ();  // stop I2C
        
        __delay_ms (1000); // 1 sec delay between write and read
        
        // read data
        I2C_Start ();  // start I2C
        I2C_Write (0xA0); // using 24aa00 slave address
        I2C_Write (0x01);  // writing into register 0x01
        I2C_RStart(); // repeated start
        I2C_Write (0xA0|0x01); // using 24aa00 slave address + read
        x = I2C_Read (1);  // read data and send NACK for memory 24aa00 see 8.1 manual
        I2C_Stop ();
        toca hacer una funcion de write y de read donde este encapsulado el 
       start, stop y demas y esa es la que uso y le paso a los drivers o la iuso en los wrappers
        Wrappers_I2CMaster_Read(,ADDR_A5,&buf,1);
 
 */
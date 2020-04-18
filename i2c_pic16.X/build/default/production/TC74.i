# 1 "TC74.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "TC74.c" 2
# 19 "TC74.c"
# 1 "./TC74.h" 1
# 20 "./TC74.h"
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 139 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 139 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 2 3
# 20 "./TC74.h" 2







typedef enum {
  ADDR_A0 =0x48,
  ADDR_A1 =0x49,
  ADDR_A2 =0x4A,
  ADDR_A3 =0x4B,
  ADDR_A4 =0x4C,
  ADDR_A5 =0x4D,
  ADDR_A6 =0x4E,
  ADDR_A7 =0x4F
}ADDR_SLAVE_7b_t;

typedef enum{
    TC74_RTR = 0x00,
    TC74_RWCR = 0x01
}TC74_Reg;



typedef void (*Write_Fcn )(uint8_t, void*, uint8_t);



typedef void (*Read_Fcn )(uint8_t, void*, uint8_t);



typedef struct {
    Write_Fcn I2CWrite;
    Read_Fcn I2CRead;
    ADDR_SLAVE_7b_t Dev_Addr;
}TC74Data_t;
# 75 "./TC74.h"
void TC74_Initialize(TC74Data_t *Obj, ADDR_SLAVE_7b_t AddrSlave ,Write_Fcn write_fcn, Read_Fcn read_fcn);





void TC74_Standby(TC74Data_t *Obj , uint8_t operation);





uint8_t TC74_Ready(TC74Data_t *Obj);





int8_t TC74_Temperature(TC74Data_t *Obj);
# 19 "TC74.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdlib.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdlib.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdlib.h" 2 3
# 21 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdlib.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 18 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 122 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 21 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdlib.h" 2 3


int atoi (const char *);
long atol (const char *);
long long atoll (const char *);
double atof (const char *);

float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);
long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);

int rand (void);
void srand (unsigned);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);
long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

div_t div (int, int);
ldiv_t ldiv (long, long);
lldiv_t lldiv (long long, long long);

typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);





size_t __ctype_get_mb_cur_max(void);
# 20 "TC74.c" 2



static uint8_t TC74_Write(TC74Data_t *Obj, uint8_t TC74_Register, uint16_t data, uint8_t amount);

static uint8_t TC74_Read(TC74Data_t *Obj, uint8_t TC74_Register, uint8_t amount);


void TC74_Initialize(TC74Data_t *Obj, ADDR_SLAVE_7b_t AddrSlave ,Write_Fcn write_fcn, Read_Fcn read_fcn){

    Obj->I2CWrite = write_fcn;
    Obj->I2CRead = read_fcn;
    Obj->Dev_Addr = AddrSlave;

}


static uint8_t TC74_Write(TC74Data_t *Obj, uint8_t TC74_Register, uint16_t data, uint8_t amount){
 uint8_t Retvalue = 1;
    uint8_t buffer[2];
 buffer[0] = TC74_Register;
 buffer[1] = data;
 if(Obj->I2CWrite != ((void*)0)){
        Obj->I2CWrite( Obj->Dev_Addr, buffer, (amount+1));
    }
    else Retvalue = 0;
    return Retvalue;
}


static uint8_t TC74_Read(TC74Data_t *Obj, uint8_t TC74_Register, uint8_t amount){
 uint8_t buffer[2];
 buffer[0] = TC74_Register;
 if(Obj->I2CRead != ((void*)0)){
        Obj->I2CRead( Obj->Dev_Addr, buffer, amount);
    }
 return buffer[0];
}


void TC74_Standby(TC74Data_t *Obj , uint8_t operation){
    uint8_t RCWR;
    operation = operation ?0x80:0x00;
    RCWR = TC74_Read(Obj,TC74_RWCR,1);
    TC74_Write(Obj,TC74_RWCR,operation ,1);
}


uint8_t TC74_Ready(TC74Data_t *Obj){
    uint8_t Ready=0;
    Ready = TC74_Read(Obj,TC74_RWCR,1);

    return ( (Ready & 0x40)?1:0 );
}


int8_t TC74_Temperature(TC74Data_t *Obj){
    uint8_t Digital_Temperature = 0;
    int8_t Temperature = 0;
    if(TC74_Ready(Obj)) {
        Digital_Temperature = TC74_Read(Obj,TC74_RTR,1);
    }

    if(Digital_Temperature > 127){
        Temperature = ((~Digital_Temperature) |0x01)*(-1) ;
    }else Temperature = (int8_t)Digital_Temperature;

    return Temperature;
}

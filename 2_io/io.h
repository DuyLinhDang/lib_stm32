#ifndef __io_H
#define __io_H   
#include "stm32f10x.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////    
//STM32VN.COM   
//////////////////////////////////////////////////////////////////////////////////     

//0, ucos
//1, ucos
#define SYSTEM_SUPPORT_OS     1 	//runos					// 0      //UCOS
                                                       
    

//IO
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//Dia chi
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 
 
//IO
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //ngo ra
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //ngo vao

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)   

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //ngo ra
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //ngo vao
#define PIN1					GPIO_PIN_1
#define PIN2					GPIO_PIN_2
#define PIN3					GPIO_PIN_3
#define PIN4					GPIO_PIN_4
#define PIN5					GPIO_PIN_5
#define PIN6					GPIO_PIN_6
#define PIN7					GPIO_PIN_7
#define PIN8					GPIO_PIN_8
#define PIN9					GPIO_PIN_9
#define PIN10					GPIO_PIN_10
#define PIN11					GPIO_PIN_11
#define PIN12					GPIO_PIN_12
#define PIN13					GPIO_PIN_13
#define PIN14					GPIO_PIN_14
#define PIN15					GPIO_PIN_15
#define PIN16					GPIO_PIN_16


void io_Set(GPIO_TypeDef* GPIOx,u16 BITx,GPIOMode_TypeDef MODE,GPIOSpeed_TypeDef OSPEED);

void WFI_SET(void);      
void INTX_DISABLE(void);
void INTX_ENABLE(void);   
void MSR_MSP(u32 addr); 
//intput
//step_number: 0~...
//dir: 0,1 left or right
//speed 8000~50000

void step_motor(GPIO_TypeDef* GPIOx, uint16_t GPIO_Step_Pin,uint16_t GPIO_Dir_Pin,uint8_t dir, uint32_t speed,uint32_t step_number);


#endif


#ifndef __myFlash_H
#define __myFlash_H  
#include "stm32f10x.h"
#include "stm32f10x_flash.h"

#endif
// gia tri tra ve cua write flash
typedef enum {
	Erorr_Rarameter = 0,
	No_Erorr
}statusFlash;

typedef struct {
	int8_t *Buffer;
	uint16_t Size;
	uint16_t Num;
	uint16_t In;
	uint16_t Out;
} USART_t;


//doc flash
void Read_Flash(uint32_t Addr, u8* data,uint32_t NumByteToRead);

//ghi flash, tra ve trang thai ghi duoc khong
statusFlash Write_Flash(u32 Addr,u8* data_write,uint32_t NumByteToRead);

//xoa flash
void ErasePage_Flash(volatile u8 NumPages);



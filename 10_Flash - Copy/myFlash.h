#ifndef __myFlash_H
#define __myFlash_H  
#include "stm32f10x.h"
#include "stm32f10x_flash.h"

// gia tri tra ve cua write flash
typedef enum {
	Erorr_Rarameter = 0;
	No_Erorr;
}statusFlash;


//doc flash
void Read_Flash(uint32_t Addr, void *data,uint32_t NumByteToRead);

//ghi flash, tra ve trang thai ghi duoc khong
statusFlash Write_Flash(u32 Addr,void *data_write,uint32_t NumByteToRead);

//xoa flash
void ErasePage_Flash(volatile u8 NumPages);



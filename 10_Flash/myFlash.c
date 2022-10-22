#include "myFlash.h"
#include "String.h"

#define PAGE_SIZE   1024       
#define PAGE_NUM    127 
//doc flash
void Read_Flash(uint32_t Addr,u8* data_read,uint32_t NumByteToRead) {		// vi tri,
	memcpy(data_read, (void *)(Addr), NumByteToRead);
}

//ghi flash, tra ve trang thai ghi duoc khong
statusFlash Write_Flash(u32 Addr,u8* data_write,uint32_t NumByteToRead){
	u32 counter =0;
	// kiem tra loi xem co tham so nao bang khong hay khong
	if( (Addr==0) || (data_write==0) || (NumByteToRead==0)){
		return Erorr_Rarameter;
	}
	// check bit busy
	while((FLASH->CR & FLASH_SR_BSY) == FLASH_SR_BSY);
	
	//Read FLASH_CR_LOCK
	while((FLASH->CR & FLASH_CR_LOCK) == FLASH_CR_LOCK){
		//Perform unlock sequency
		FLASH_Unlock();
	}
	
	//Write FLASH_CR_PG to 1
	FLASH->CR |= FLASH_CR_PG;
	
	//ghi/////////////////////
	// kiem tra so luong ghi bao nhieu byte
	
	//khai bao bien dem so byte ghi
	for(counter =0;counter<NumByteToRead;counter++)
	{
		// neu chia het cho 4 thi ghi 4 byte
//		if(((NumByteToRead-counter)>=4) && (Addr%4==0) && (((u32) data_write)%4==0)){
//			*(u32 *)(Addr + counter) = *(u32 *)(data_write + counter);
//			counter=counter+3;
//		}
		// neu chia het cho 2 thi ghi 2 byte
		if(((NumByteToRead-counter)>=2) && (Addr%2==0) && (((u32) data_write)%2==0)){
			*(u16 *)(Addr + counter) = *(u16 *)(data_write + counter);
			counter=counter+1;
		}
		else {
			*(u8 *)(Addr + counter) = *(u8 *)(data_write + counter);
		}
	}
	
	while((FLASH->SR & FLASH_SR_BSY) == FLASH_SR_BSY);
	
	// xoa bit ve 0
	FLASH->CR &= ~FLASH_CR_PG;
	
	return No_Erorr;
	
}

void ErasePage_Flash(volatile u8 NumPages){
	while(((FLASH->CR >> 1U) & 0x01U )== FLASH_SR_BSY){
	}
	
	//Read FLASH_CR_LOCK
	while((FLASH->CR & FLASH_CR_LOCK) == FLASH_CR_LOCK){
		//Perform unlock sequency
		FLASH_Unlock();
	}
	
	//Write FLASH_CR_PER to 1
	FLASH->CR |= FLASH_CR_PER;
	
	//Write into FAR an address within the page to erase
	FLASH->AR = ((u32)(NumPages*PAGE_SIZE)+0x08000000);
	
	//Write FLASH_CR_STRT to 1
	FLASH->CR |= FLASH_CR_STRT;
	
	//FLASH_SR_BSY = 1
	while((FLASH->CR & FLASH_SR_BSY) == FLASH_SR_BSY);
	
	//xoa ca bit da set len
	FLASH->CR &= ~FLASH_CR_PER;
	FLASH->CR &= ~FLASH_CR_STRT;
	//FLASH->CR &= ~FLASH_CR_PER;
}



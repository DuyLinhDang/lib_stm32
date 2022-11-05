#include "system.h"

extern unsigned char gImage_MinhPhuong[];

int main(){
	
	SystemInit();
	delay_init(72);	 
	LCD_Init();	
	while(1){
		Gui_DrawbmpUser(10,10,210,245,gImage_MinhPhuong);
	}
}

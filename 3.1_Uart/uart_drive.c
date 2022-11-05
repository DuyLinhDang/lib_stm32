#include "io.h"
#include "delay.h"
#include "pwm.h"
#include "timer.h"
//thu vien c
//#pragma import(__use_no_semihosting_swi)
#pragma import (__ use_no_semihosting)
#include "String.h"
#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"
#include "cJSON.h"

#define SizeData 200
char RX_data[SizeData];
u16 index1 = 0;
void Clear_Data_RX();
void UART_Config();
void USART1_IRQHandler(void);
void USRAT1_PutChar(char data);
void USRAT1_PutString(char *n);
struct __FILE{
	int dummy;
};
	//FILE __stdout;
int fpuc(int ch, FILE *f){
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TC));
	USART_SendData(USART1,(u8) ch);
	return ch;
}

 // con tro json
void XuLyJson(char *data3);
u32 i;
u16 a = 97;
char z = 10;
int main(void){
	
	io_Set(GPIOC,GPIO_Pin_13,GPIO_Mode_Out_PP,GPIO_Speed_50MHz);
	
	UART_Config();
	USRAT1_PutChar(97);
	while(1){
		USRAT1_PutString("hello");
		for(i =0;i<1000000;i++){
		}
	}
}

void UART_Config(){
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);	//USART1£¬GPIOA
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	
  GPIO_Init(GPIOA, &GPIO_InitStructure);//GPIOA.9
   
  //USART1_RX	  GPIOA.10
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);//GPIOA.10  

  //Usart1 NVIC 
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			
	NVIC_Init(&NVIC_InitStructure);	
  
   //USART 

	USART_InitStructure.USART_BaudRate = 9600;////////
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;////
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//////

  USART_Init(USART1, &USART_InitStructure); 
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
  USART_Cmd(USART1, ENABLE); 
	}

void USART1_IRQHandler(void) {
	//Check if interrupt was because data is received
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
		//res = USART1->DR;
		char data = NULL;
		data = USART_ReceiveData(USART1);
		if(data != '\n') RX_data[index1++] = data;
		else{
			// xu ly
			USRAT1_PutString(RX_data);
		//	if(strstr(RX_data,"A")) GPIO_SetBits(GPIOC,GPIO_Pin_13);
			//if(strstr(RX_data,"B")) GPIO_ResetBits(GPIOC,GPIO_Pin_13);
			// xu ly json
			XuLyJson(RX_data);
			Clear_Data_RX();
		}
	}
}

void USRAT1_PutChar(char data){
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TC));
	USART_SendData(USART1,data);
		//USART_SendData
	
}

void USRAT1_PutString(char *n){
	while(*n){
		USRAT1_PutChar(*n++);
	}
}

void Clear_Data_RX(){
	u16 j=0;
	for(j=0;j<SizeData;j++){
		RX_data[j] = NULL;
	}
	index1 = 0;
}

void XuLyJson(char *data3){
	//cJSON_Delete(DataJson);
	cJSON* DataJson = cJSON_Parse(data3);// dua du vao dang json
	//xu ly
	if(cJSON_GetObjectItem(DataJson,"led1")){ // kiem tra xem co oject "led_on" hay khong
		if(strstr(cJSON_GetObjectItem(DataJson,"led1")->valuestring,"0")){
			//led off
			GPIO_SetBits(GPIOC,GPIO_Pin_13);
			printf("off");
		}
		else if(strstr(cJSON_GetObjectItem(DataJson,"led1")->valuestring,"1")){
			//led on
			GPIO_ResetBits(GPIOC,GPIO_Pin_13);
			printf("on");
		}
		
	}
	else if(cJSON_GetObjectItem(DataJson,"led2")){
		
	}
	
	
	//xu ly xong xoa du lieu
	cJSON_Delete(DataJson);
	
}


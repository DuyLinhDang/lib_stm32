#ifndef __exit_H
#define __exit_H    
#include "stm32f10x.h"
//////////////////////////////////////////////////////////////////////////////////    
                          
//////////////////////////////////////////////////////////////////////////////////     
 /* Includes
 */

/* Default priority for NVIC */
#ifndef EXTI_PRIORITY
#define EXTI_PRIORITY   0x0A
#endif
/**
 * Interrupt trigger enumeration
 * 
 * Parameters:
 *    - EXTI_Trigger_Rising:
 *       Trigger interrupt on rising edge on line
 *    - EXTI_Trigger_Falling:
 *       Trigger interrupt on falling edge on line
 *    - EXTI_Trigger_Rising_Falling:
 *       Trigger interrupt on any edge on line
 */
typedef enum {
   Trigger_Rising = 0x08,
   Trigger_Falling = 0x0C,
   Trigger_Rising_Falling = 0x10
} Trigger_t;

void exit_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,Trigger_t trigger);                         
#endif

#ifndef __TIMER_H
#define __TIMER_H
#include "io.h"


void TIM3_Int_Init(u16 arr,u16 psc);
void TIM2_Int_Init(u16 arr,u16 psc);
// thay doi ten timer
void TIM3_PWM_Init(u16 arr,u16 psc);
#endif

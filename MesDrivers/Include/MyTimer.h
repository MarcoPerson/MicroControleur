#ifndef TIMER_H

#define TIMER_H
#include "stm32f10x.h"

typedef struct
	{
		TIM_TypeDef * Timer ; // TIM1 � TIM4
		unsigned short ARR ;
		unsigned short PSC ;
} MyTimer_Struct_TypeDef ;
	
/*
*****************************************************************************************
* @brif
* @param -> Param�tre sous forme d � une structure ( son adresse ) contenant les
informations de base
* @Note -> Fonction � lancer syst�matiquement avant d � aller plus en d�tail dans les
conf plus fines (PWM, codeur inc ... )
*************************************************************************************************
*/

void MyTimer_Base_Init (MyTimer_Struct_TypeDef * Timer );

#define MyTimer_Base_Start(Timer) (Timer->CR1 |= 0x01)

#define MyTimer_Base_Stop(Timer) ( Timer->CR1 &= ~0x01 )

#endif

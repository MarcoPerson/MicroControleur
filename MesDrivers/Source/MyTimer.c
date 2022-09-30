#include "MyTimer.h"

void MyTimer_Base_Init (MyTimer_Struct_TypeDef * Timer ) {
	if(Timer->Timer == TIM1){
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	if(Timer->Timer == TIM2){
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	}
	if(Timer->Timer == TIM3){
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	}
	if(Timer->Timer == TIM4){
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	
	Timer->Timer->ARR = Timer->ARR;
	Timer->Timer->PSC = Timer->PSC;
}

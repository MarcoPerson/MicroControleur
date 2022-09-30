#include "stm32f10x.h"
#include "MyTimer.h"

MyTimer_Struct_TypeDef Timer2;

int main(void){
	
	/*RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->ARR=10000-1;
	TIM2->PSC=3600-1;
	TIM2->CR1 |= 0x01;*/
	
	Timer2.Timer = TIM2;
	Timer2.ARR = 10000-1;
	Timer2.PSC = 3600-1;
	MyTimer_Base_Init(&Timer2);
	MyTimer_Base_Start(Timer2.Timer);
	
	while(1)
	{
		if(Timer2.Timer->CNT > 5000){
			MyTimer_Base_Stop(Timer2.Timer);
		}
	}
}

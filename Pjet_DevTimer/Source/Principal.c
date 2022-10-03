#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"



MyGPIO_Struct_TypeDef PC10;
MyTimer_Struct_TypeDef Timer2;

void callback(void){
	MyGPIO_Toggle(PC10.GPIO, PC10.GPIO_Pin);
}


int main(void){
	
	/*RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->ARR=10000-1;
	TIM2->PSC=3600-1;
	TIM2->CR1 |= 0x01;*/
	
	Timer2.Timer = TIM1;
	Timer2.ARR = 10000-1;
	Timer2.PSC = 3600-1;
	MyTimer_Base_Init(&Timer2);
	MyTimer_Base_Start(Timer2.Timer);
	
	PC10.GPIO = GPIOC;
	PC10.GPIO_Pin = 10;
  PC10.GPIO_Conf = Out_OD;
	
	MyGPIO_Init(&PC10);
	MyTimer_ActiveIT ( Timer2.Timer, 0 , callback);
	
	while(1)
	{
		/*if(Timer2.Timer->CNT > 5000){
			MyTimer_Base_Stop(Timer2.Timer);
		}*/
		
	}
}

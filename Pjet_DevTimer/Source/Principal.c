#include "stm32f10x.h"
#include "MyTimer.h"
#include "Driver_GPIO.h"



MyGPIO_Struct_TypeDef PA0;
MyTimer_Struct_TypeDef Timer2;

void callback(void){
	MyGPIO_Toggle(PA0.GPIO, PA0.GPIO_Pin);
}


int main(void){
	
	/*RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->ARR=10000-1;
	TIM2->PSC=3600-1;
	TIM2->CR1 |= 0x01;*/
	
	Timer2.Timer = TIM2;
	Timer2.ARR = 72-1;
	Timer2.PSC = 10-1;
	MyTimer_Base_Init(&Timer2);
	MyTimer_Base_Start(Timer2.Timer);
	
	PA0.GPIO = GPIOA;
	PA0.GPIO_Pin = 0;
  PA0.GPIO_Conf = AltOut_Ppull;
	
	MyGPIO_Init(&PA0);
	
	MyTimer_PWM( Timer2.Timer , 1 );
	MyTimer_Ratio (Timer2.Timer , 1, 20);
	
	MyTimer_ActiveIT ( Timer2.Timer, 0 , callback);
	
	while(1)
	{
		/*if(Timer2.Timer->CNT > 5000){
			MyTimer_Base_Stop(Timer2.Timer);
		}*/
		
	}
}

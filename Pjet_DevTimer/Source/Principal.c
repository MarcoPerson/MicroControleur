#include "stm32f10x.h"

int main(void){
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	//GPIOC->CRH |= ((0x01 << 9) | (0x01 << 2));
	//GPIOC->CRH &= ~((0x01 << 11) | (0x01 << 10) | (0x01 << 8) | (0x01 << 3) |(0x01 << 1) | (0x01 << 0));
	
	//Open Drain
	GPIOC->CRH |= ((0x01 << 10) | (0x01 << 9) | (0x01 << 2));
	GPIOC->CRH &= ~((0x01 << 11) | (0x01 << 8) | (0x01 << 3) |(0x01 << 1) | (0x01 << 0));
	
	while(1){
		if ((GPIOC->IDR & GPIO_IDR_IDR8) != 0){
			GPIOC->ODR &= ~(GPIO_ODR_ODR10);
		}
		else{
			GPIOC->ODR |= GPIO_ODR_ODR10;
		}
	}
}

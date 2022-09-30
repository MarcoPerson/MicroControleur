#include "stm32f10x.h"
#include "Driver_GPIO.h"


int main(void){
	/*GPIOC->CRH |= ((0x01 << 9) | (0x01 << 2));
	GPIOC->CRH &= ~((0x01 << 11) | (0x01 << 10) | (0x01 << 8) | (0x01 << 3) |(0x01 << 1) | (0x01 << 0));
	
	//Open Drain
	GPIOC->CRH |= ((0x01 << 10) | (0x01 << 9) | (0x01 << 2));
	GPIOC->CRH &= ~((0x01 << 11) | (0x01 << 8) | (0x01 << 3) |(0x01 << 1) | (0x01 << 0));
	*/
	//int state=0;
	MyGPIO_Struct_TypeDef PC8, PC10;
	PC8.GPIO = GPIOC;
	PC8.GPIO_Pin = 8;
	PC8.GPIO_Conf = In_Floating;
	
	PC10.GPIO = GPIOC;
	PC10.GPIO_Pin = 10;
  PC10.GPIO_Conf = Out_OD;
	
	MyGPIO_Init(&PC8);
	MyGPIO_Init(&PC10);
	
	
	
	
	while(1){
		if (MyGPIO_Read(PC8.GPIO, PC8.GPIO_Pin) != 0){
			MyGPIO_Reset(PC10.GPIO, PC10.GPIO_Pin);
		}
		else{
			MyGPIO_Set(PC10.GPIO, PC10.GPIO_Pin);
		}
	}
}


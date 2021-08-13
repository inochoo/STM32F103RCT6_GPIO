#include<stm32f1xx.h>
void SystemClockInit()
{
	RCC->CR |= 1<<0;
	while((RCC->CR & (uint32_t)(1<<1)) == 0);
	RCC->APB2ENR |= 1<<4;
}
void GPIO_Init()
{
	GPIOC->CRL |= (1<<0) | (1<<4);
	GPIOC->CRL &= ~(3<<2) ;
	GPIOC->CRL &= ~(3<<6) ;
}
void delay(uint32_t time)
{
	while(time--);
}

int main()
{
	SystemClockInit();
	GPIO_Init();
	while(1)
	{
		GPIOC->BSRR |= 3<<0;
		delay(720000);
		GPIOC->BRR |= 3<<0;
		delay(720000);
	}
	return 0;
}

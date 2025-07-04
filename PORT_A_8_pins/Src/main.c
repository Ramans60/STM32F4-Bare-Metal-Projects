volatile unsigned int *RCC_CR =(volatile unsigned int*)0x40023800;
volatile unsigned int *RCC_CFGR=(volatile unsigned int*)0x40023808;
volatile unsigned int *RCC_AHB1ENR=(volatile unsigned int*)0x40023830;

volatile unsigned int *GPIOA_MODER=(volatile unsigned int*)0x40020000;
volatile unsigned int *GPIOA_ODR=(volatile unsigned int*)0x40020014;
int main()
{
	*RCC_CR &=~(1<<16);
	*RCC_CR |=(1<<16);

	*RCC_CFGR &=~(1<<3);
	*RCC_CFGR |=(1<<3);

	*RCC_AHB1ENR |=(1<<0);

	*GPIOA_MODER &=~(1<<0);
	*GPIOA_MODER |=(1<<0);

	*GPIOA_ODR |=(1<<0);

	*GPIOA_MODER &=~(1<<2);
	*GPIOA_MODER |=(1<<2);

	*GPIOA_ODR |=(1<<1);

	*GPIOA_MODER &=~(1<<4);
	*GPIOA_MODER |=(1<<4);

	*GPIOA_ODR |=(1<<2);

	*GPIOA_MODER &=~(1<<6);
	*GPIOA_MODER |=(1<<6);

	*GPIOA_ODR |=(1<<3);

	*GPIOA_MODER &=~(1<<8);
	*GPIOA_MODER |=(1<<8);

	*GPIOA_ODR |=(1<<4);

	*GPIOA_MODER &=~(1<<10);
	*GPIOA_MODER |=(1<<10);

	*GPIOA_ODR |=(1<<5);

	*GPIOA_MODER &=~(1<<12);
	*GPIOA_MODER |=(1<<12);

	*GPIOA_ODR |=(1<<6);

	*GPIOA_MODER &=~(1<<14);
	*GPIOA_MODER |=(1<<14);

	*GPIOA_ODR |=(1<<7);

	*GPIOA_MODER &=~(1<<16);
	*GPIOA_MODER |=(1<<16);

	*GPIOA_ODR |=(1<<8);

	*GPIOA_MODER &=~(1<<18);
	*GPIOA_MODER |=(1<<18);

	*GPIOA_ODR |=(1<<9);

	*GPIOA_MODER &=~(1<<20);
	*GPIOA_MODER |=(1<<20);

	*GPIOA_ODR |=(1<<10);

	*GPIOA_MODER &=~(1<<22);
	*GPIOA_MODER |=(1<<22);

	*GPIOA_ODR |=(1<<11);

	*GPIOA_MODER &=~(1<<24);
	*GPIOA_MODER |=(1<<24);

	*GPIOA_ODR |=(1<<12);
}

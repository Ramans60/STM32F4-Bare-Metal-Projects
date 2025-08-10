volatile unsigned int *RCC_CR =(volatile unsigned int*)0x40023800;
volatile unsigned int *RCC_CFGR=(volatile unsigned int*)0x40023808;
volatile unsigned int *RCC_AHB1ENR=(volatile unsigned int*)0x40023830;

volatile unsigned int *GPIOA_MODER=(volatile unsigned int*)0x40020000;
volatile unsigned int *GPIOA_ODR=(volatile unsigned int*)0x40020014;
volatile unsigned int *GPIOA_IDR   = (volatile unsigned int*)0x40020010;


volatile unsigned int *GPIOB_MODER=(volatile unsigned int*)0x40020400;
volatile unsigned int *GPIOB_ODR=(volatile unsigned int*)0x40020414;
void delay()
{
	int i = 0;
	while (i < 900000) {
	    __asm("NOP");
	    i++;
	}

}

int main()
{
	*RCC_CR &=~(1<<16);
	*RCC_CR |=(1<<16);

	*RCC_CFGR &=~(1<<0);
	*RCC_CFGR |=(1<<0);


	*RCC_AHB1ENR |= (1 << 0);
	*RCC_AHB1ENR |= (1 << 1);


	*GPIOA_MODER &= ~(1 << 0);
	*GPIOA_MODER &= ~(1 << 1);


	*GPIOB_MODER &= ~(1 << 0);
	*GPIOB_MODER &= ~(1 << 1);
	*GPIOB_MODER |=  (1 << 0);


    while(1)
    {
        if( (*GPIOA_IDR & (1<<0)) == 0 )
        {

            *GPIOB_ODR |= (1<<0);
        }
        else
        {

            *GPIOB_ODR &= ~(1<<0);
        }
    }
}

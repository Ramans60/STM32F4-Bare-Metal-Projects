volatile unsigned int *RCC_CR =(volatile unsigned int*)0x40023800;
volatile unsigned int *RCC_CFGR=(volatile unsigned int*)0x40023808;
volatile unsigned int *RCC_AHB1ENR=(volatile unsigned int*)0x40023830;

volatile unsigned int *GPIOA_MODER=(volatile unsigned int*)0x40020000;
volatile unsigned int *GPIOA_ODR=(volatile unsigned int*)0x40020014;

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

	*RCC_AHB1ENR |=(1<<0);
	*RCC_AHB1ENR |=(1<<1);


    int j = 0;
    while (j <= 14) {
        *GPIOA_MODER &= ~(1 << j);
        *GPIOA_MODER |=  (1 << j);
        j += 2;
    }


    int i = 0;
    while (i <= 24)
    {
    	if ((i>=0&&i<=4)||(i>=10&&i<=30))
    	{
            *GPIOB_MODER &= ~(1 << i);
            *GPIOB_MODER |=  (1 << i);
    	}
        i += 2;
    }



	*GPIOB_ODR |=(1<<0);
	*GPIOB_ODR |=(1<<1);
	*GPIOB_ODR |=(1<<2);
	*GPIOB_ODR |=(1<<5);
	*GPIOB_ODR |=(1<<6);
	*GPIOB_ODR |=(1<<7);
	*GPIOB_ODR |=(1<<8);
	*GPIOB_ODR |=(1<<9);


    while (1) {

        i = 0;
        while (i <= 7) {
            *GPIOA_ODR = (1 << i);
            delay();
            i++;
        }

    }

}

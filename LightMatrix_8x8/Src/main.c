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
	while (i < 90000) {
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
    	if ((i>=0&&i<=4)||(i>=10&&i<=18))
    	{
            *GPIOB_MODER &= ~(1 << i);
            *GPIOB_MODER |=  (1 << i);
    	}
        i += 2;
    }



    while(1)
    {
        for (i=0; i<8; i++)
        {
            for (j=0; j<10; j++)
            {
                if(j != 3 && j != 4)
                {
                    *GPIOA_ODR |= (1<<i);
                    *GPIOB_ODR |= (1<<j);
                    delay();
                    *GPIOA_ODR &= ~(1<<i);
                    *GPIOB_ODR &= ~(1<<j);
                    delay();
                }
            }
        }
    }
}

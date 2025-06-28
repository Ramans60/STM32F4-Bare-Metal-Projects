volatile unsigned int *RCC_CR      = (volatile unsigned int *)0x40023800;
volatile unsigned int *RCC_CFGR    = (volatile unsigned int *)0x40023808;
volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int *)0x40023830;

volatile unsigned int *GPIOC_MODER = (volatile unsigned int *)0x40020800;
volatile unsigned int *GPIOC_ODR   = (volatile unsigned int *)0x40020814;

void delay()
{
	 for (int i = 0; i < 4000000; i++) __asm("NOP");
}

int main(void)
{

    *RCC_CR &= ~(1 << 16);
    *RCC_CR |=  (1 << 16);
    while (!(*RCC_CR & (1 << 17)));


    *RCC_CFGR &= ~(0x3);
    *RCC_CFGR |= (1 << 0);
    while (((*RCC_CFGR >> 2) & 0x3) != 1);


    *RCC_AHB1ENR |= (1 << 2);


    *GPIOC_MODER &= ~(3 << 26);
    *GPIOC_MODER |=  (1 << 26);
    while (1)
    {
        *GPIOC_ODR &= ~(1 << 13);
        delay();
        *GPIOC_ODR |= (1 << 13);
        delay();
    }
}

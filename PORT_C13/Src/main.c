volatile unsigned int *RCC_CR      = (volatile unsigned int*)0x40023800;
volatile unsigned int *RCC_CFGR    = (volatile unsigned int*)0x40023808;
volatile unsigned int *RCC_AHB1ENR = (volatile unsigned int*)0x40023830;

volatile unsigned int *GPIOC_MODER = (volatile unsigned int*)0x40020800;
volatile unsigned int *GPIOC_ODR   = (volatile unsigned int*)0x40020814;

int main()
{
        *RCC_CR &= ~(1<<16);
        *RCC_CR |=  (1<<16);

        *RCC_CFGR &= ~(1<<3);
        *RCC_CFGR |= (1<<3);

        *RCC_AHB1ENR |= (1<<2);

        *GPIOC_MODER &= ~(1<<26);
        *GPIOC_MODER |= (1<<26);


        *GPIOC_ODR &= ~(1<<13);

}

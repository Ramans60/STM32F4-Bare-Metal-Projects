volatile unsigned int *RCC_CR       = (volatile unsigned int*)0x40023800;
volatile unsigned int *RCC_CFGR     = (volatile unsigned int*)0x40023808;
volatile unsigned int *RCC_AHB1ENR  = (volatile unsigned int*)0x40023830;

volatile unsigned int *GPIOA_MODER  = (volatile unsigned int*)0x40020000;
volatile unsigned int *GPIOA_ODR    = (volatile unsigned int*)0x40020014;

void delay() {
    for (volatile int i = 0; i < 99999; i++) {
        __asm("NOP");
    }
}

int main(void)
{
    *RCC_CR &= ~(1 << 16);
    *RCC_CR |=  (1 << 16);
    while (!(*RCC_CR & (1 << 17)));

    *RCC_CFGR &= ~(0x3);
    *RCC_CFGR |=  (1 << 0);
    while (((*RCC_CFGR >> 2) & 0x3) != 1);

    *RCC_AHB1ENR |= (1 << 0);

    int i = 0;
    while (i <= 14) {
        *GPIOA_MODER &= ~(3 << i);
        *GPIOA_MODER |=  (1 << i);
        i += 2;
    }

    while (1) {

        i = 0;
        while (i <= 7) {
            *GPIOA_ODR = (1 << i);
            delay();
            i++;
        }


        i = 6;
        while (i >= 1) {
            *GPIOA_ODR = (1 << i);
            delay();
            i--;
        }
    }
}

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
	while (i < 20000) {
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
    int arr[64][2]={
                    {4,5},
                    {4,6},
                    {3,6},
                    {3,5},
                    {3,2},
                    {4,2},
                    {5,2},
                    {5,5},
                    {5,6},
                    {5,7},
                    {4,7},
                    {3,7},
                    {2,7},
                    {2,6},
                    {2,5},
                    {2,2},
                    {2,1},
                    {3,1},
                    {4,1},
                    {5,1},
                    {6,1},
                    {6,2},
                    {6,5},
                    {6,6},
                    {6,7},
                    {6,8},
                    {5,8},
                    {4,8},
                    {3,8},
                    {2,8},
                    {1,8},
                    {1,7},
                    {1,6},
                    {1,5},
                    {1,2},
                    {1,1},
                    {1,0},
                    {2,0},
                    {3,0},
                    {4,0},
                    {5,0},
                    {6,0},
                    {7,0},
                    {7,1},
                    {7,2},
                    {7,5},
                    {7,6},
                    {7,7},
                    {7,8},
                    {7,9},
                    {6,9},
                    {5,9},
                    {4,9},
                    {3,9},
                    {2,9},
                    {1,9},
                    {0,9},
                    {0,8},
                    {0,7},
                    {0,6},
                    {0,5},
                    {0,2},
                    {0,1},
                    {0,0}
                 };

    while (1)
    {
        for(i=0; i<64; i++)
        {
            for (j=0; j<2; j++)
            {
            	*GPIOA_ODR |= (1<<arr[i][0]);

            	*GPIOB_ODR |= (1<<arr[i][1]);
            	delay();
            	delay();
            	delay();
            	delay();
            	delay();
            	delay();

            	*GPIOA_ODR &= ~(1<<arr[i][0]);

            	*GPIOB_ODR &= ~(1<<arr[i][1]);


            }
        }
    	delay();

    }
}

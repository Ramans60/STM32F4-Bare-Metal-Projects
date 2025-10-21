volatile unsigned int *RCC_CR =(volatile unsigned int*)0x40023800;
volatile unsigned int *RCC_CFGR=(volatile unsigned int*)0x40023808;
volatile unsigned int *RCC_AHB1ENR=(volatile unsigned int*)0x40023830;

volatile unsigned int *GPIOA_MODER=(volatile unsigned int*)0x40020000;
volatile unsigned int *GPIOA_ODR=(volatile unsigned int*)0x40020014;

volatile unsigned int *GPIOB_MODER=(volatile unsigned int*)0x40020400;
volatile unsigned int *GPIOB_ODR=(volatile unsigned int*)0x40020414;



void delay()
{
    volatile int i = 0;
    while (i < 100)
    {
        __asm("NOP");
        i++;
    }
}

void delay1()
{
    volatile long long i = 0;
    while (i < 1900000)
    {
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
    while (j <= 14)
    {
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
    // 0
    int arr0[19][2] = {
    		{0,6},{0,7},{0,8},{1,5},{1,9},{2,5},{2,8},{2,9},{3,5},
			{3,7},{3,9},{4,5},{4,6},{4,9},{5,5},{5,9},{6,6},
			{6,7},{6,8}
    };
    // 9
    int arr9[16][2] = {
    		{0,6},{0,7},{0,8},{1,5},{1,9},{2,5},{2,9},{3,5},{3,6},
			{3,7},{3,8},{4,5},{5,6},{6,7},{6,8},{6,9}
    };
    // 8
    int arr8[17][2] = {
    		{0,6},{0,7},{0,8},{1,5},{1,9},{2,5},{2,9},{3,6},{3,7},
			{3,8},{4,5},{4,9},{5,5},{5,9},{6,6},{6,7},{6,8}
    };
    // 7
    int arr7[11][2] = {
    		{0,5},{0,6},{0,7},{0,8},{0,9},{1,5},{2,5},{3,6},{4,7},
			{5,8},{6,9}
    };
    // 6
    int arr6[16][2] = {
    		{0,5},{0,6},{0,7},{1,8},{2,9},{3,6},{3,7},{3,8},{3,9},
			{4,5},{4,9},{5,5},{5,9},{6,6},{6,7},{6,8}
    };
    // 5
    int arr5[17][2] = {
    		{0,5},{0,6},{0,7},{0,8},{0,9},{1,9},{2,6},{2,7},{2,8},
			{2,9},{3,5},{4,5},{5,5},{5,9},{6,6},{6,7},{6,8}
    };
    // 4
    int arr4[14][2] = {
    		{0,6},{1,6},{1,7},{2,6},{2,8},{3,6},{3,9},{4,5},{4,6},
			{4,7},{4,8},{4,9},{5,6},{6,6}
    };
    // 3
    int arr3[15][2] = {
    		{0,5},{0,6},{0,7},{0,8},{0,9},{1,5},{2,6},{3,6},{3,7},
			{4,5},{5,5},{5,9},{6,6},{6,7},{6,8}
    };
    // 2
    int arr2[16][2] = {
    		{0,6},{0,7},{0,8},{1,5},{1,9},{2,5},{3,6},{3,7},{3,8},
			{4,9},{5,9},{6,5},{6,6},{6,7},{6,8},{6,9}
    };
    //1
    int arr1[10][2] = {
    		{0,7},{1,7},{1,8},{2,7},{3,7},{4,7},{5,7},{6,6},{6,7},{6,8}
    };

    while (1)
    {
    	int c = 10000;
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 19; i++)
    		{
    			*GPIOA_ODR |= (1 << arr0[i][0]);
    			*GPIOB_ODR |= (1 << arr0[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arr0[i][0]);
    			*GPIOB_ODR &= ~(1 << arr0[i][1]);
    		}
    	}
    	delay1();
       for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 16; i++)
    		{
    			*GPIOA_ODR |= (1 << arr9[i][0]);
    			*GPIOB_ODR |= (1 << arr9[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arr9[i][0]);
    			*GPIOB_ODR &= ~(1 << arr9[i][1]);
    		}
    	}
    	delay1();
       for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 17; i++)
    		{
    			*GPIOA_ODR |= (1 << arr8[i][0]);
    			*GPIOB_ODR |= (1 << arr8[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arr8[i][0]);
    			*GPIOB_ODR &= ~(1 << arr8[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 11; i++)
    		{
    			*GPIOA_ODR |= (1 << arr7[i][0]);
    			*GPIOB_ODR |= (1 << arr7[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arr7[i][0]);
    			*GPIOB_ODR &= ~(1 << arr7[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 16; i++)
    		{
    			*GPIOA_ODR |= (1 << arr6[i][0]);
    			*GPIOB_ODR |= (1 << arr6[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arr6[i][0]);
    			*GPIOB_ODR &= ~(1 << arr6[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 17; i++)
    		{
    			*GPIOA_ODR |= (1 << arr5[i][0]);
    			*GPIOB_ODR |= (1 << arr5[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arr5[i][0]);
    			*GPIOB_ODR &= ~(1 << arr5[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 14; i++)
    		{
    			*GPIOA_ODR |= (1 << arr4[i][0]);
    			*GPIOB_ODR |= (1 << arr4[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arr4[i][0]);
    			*GPIOB_ODR &= ~(1 << arr4[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 15; i++)
    		{
    			*GPIOA_ODR |= (1 << arr3[i][0]);
    			*GPIOB_ODR |= (1 << arr3[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arr3[i][0]);
    			*GPIOB_ODR &= ~(1 << arr3[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 16; i++)
    		{
    			*GPIOA_ODR |= (1 << arr2[i][0]);
    			*GPIOB_ODR |= (1 << arr2[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arr2[i][0]);
    			*GPIOB_ODR &= ~(1 << arr2[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 10; i++)
    		{
    			*GPIOA_ODR |= (1 << arr1[i][0]);
    			*GPIOB_ODR |= (1 << arr1[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arr1[i][0]);
    			*GPIOB_ODR &= ~(1 << arr1[i][1]);
    		}
    	}
    	delay1();
    }
}

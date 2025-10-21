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
    while (i < 190000)
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
    // A
    int arrA[14][2] = {
    		{2,6},{2,7},{2,8},{3,5},{4,5},{4,6},{4,7},{4,8},{5,5},{5,9},
			{6,5},{6,6},{6,7},{6,8}
    };
    // B
    int arrB[16][2] = {
    		{0,9},{1,9},{2,6},{2,7},{2,8},{2,9},{3,5},{3,9},{4,5},{4,9},
			{5,5},{5,9},{6,6},{6,7},{6,8},{6,9}
    };
    // C
    int arrC[11][2] = {
    		{2,5},{2,6},{2,7},{2,8},{3,9},{4,9},{5,9},{6,5},{6,6},{6,7},
			{6,8}
    };
    // D
    int arrD[16][2] = {
    		{0,5},{1,5},{2,5},{2,6},{2,7},{2,8},{3,5},{3,9},{4,5},{4,9},
			{5,5},{5,9},{6,5},{6,6},{6,7},{6,8}
    };
    // E
    int arrE[14][2] = {
    		{2,6},{2,7},{2,8},{3,5},{3,9},{4,5},{4,6},{4,7},{4,8},{4,9},
			{5,9},{6,6},{6,7},{6,8}
    };
    // F
    int arrF[9][2] = {
    		{0,6},{0,7},{1,8},{2,7},{2,8},{3,8},{4,8},{5,8},{6,8}
    };
    // G
    int arrG[17][2] = {
    		{0,6},{0,7},{0,8},{1,5},{1,9},{2,5},{2,9},{3,5},{3,9},{4,5},
			{4,6},{4,7},{4,8},{5,5},{6,6},{6,7},{6,8}
    };
    // H
    int arrH[14][2] = {
    		{0,9},{1,9},{2,6},{2,7},{2,8},{2,9},{3,5},{3,9},{4,5},{4,9},
			{5,5},{5,9},{6,5},{6,9}
    };
    // I
    int arrI[6][2] = {
    		{0,7},{2,7},{3,7},{4,7},{5,7},{6,7}
    };
    //J
    int arrJ[7][2] = {
    		{0,6},{2,6},{3,6},{4,6},{5,6},{6,7},{6,8}
    };
    // K
    int arrK[13][2] = {
    		{0,9},{1,9},{2,5},{2,9},{3,6},{3,9},{4,7},{4,8},{4,9},{5,6},
			{5,9},{6,5},{6,9}
    };
    // L
    int arrL[7][2] = {
    		{0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,6}
    };
    // M
    int arrM[14][2] = {
    		{2,6},{2,8},{3,5},{3,7},{3,9},{4,5},{4,7},{4,9},{5,5},{5,7},
			{5,9},{6,5},{6,7},{6,9}
    };
    // N
    int arrN[11][2] = {
    		{2,6},{2,7},{2,8},{3,5},{3,9},{4,5},{4,9},{5,5},{5,9},{6,5},
    		{6,9}
    };
    // O
    int arrO[12][2] = {
    		{2,6},{2,7},{2,8},{3,5},{3,9},{4,5},{4,9},{5,5},{5,9},{6,6},
			{6,7},{6,8}
    };
    // P
    int arrP[14][2] = {
    		{1,6},{1,7},{1,8},{1,9},{2,5},{2,9},{3,5},{3,9},{4,6},{4,7},
			{4,8},{4,9},{5,9},{6,9}
    };
    // Q
    int arrQ[14][2] = {
    		{1,5},{1,6},{1,7},{1,8},{2,5},{2,9},{3,5},{3,9},{4,5},{4,6},
			{4,7},{4,8},{5,5},{6,5}
    };
    // R
    int arrR[8][2] = {
    		{2,5},{2,6},{2,7},{2,8},{3,9},{4,9},{5,9},{6,9}
    };
    // S
    int arrS[13][2] = {
    		{2,5},{2,6},{2,7},{2,8},{3,9},{4,6},{4,7},{4,8},{5,5},{6,6},
			{6,7},{6,8},{6,9}
    };
    //T
    int arrT[10][2] = {
    		{0,7},{1,7},{2,6},{2,7},{2,8},{3,7},{4,7},{5,7},{6,5},{6,6}
    };
    // U
    int arrU[11][2] = {
    		{2,5},{2,9},{3,5},{3,9},{4,5},{4,9},{5,5},{5,9},{6,6},{6,7},
			{6,8}
    };
    // V
    int arrV[9][2] = {
    		{2,5},{2,9},{3,5},{3,9},{4,6},{4,8},{5,6},{5,8},{6,7}
    };
    // W
    int arrW[14][2] = {
    		{2,5},{2,7},{2,9},{3,5},{3,7},{3,9},{4,5},{4,7},{4,9},{5,5},
			{5,7},{5,9},{6,6},{6,8}
    };
    // X
    int arrX[9][2] = {
    		{2,5},{2,9},{3,6},{3,8},{4,7},{5,6},{5,8},{6,5},{6,9}
    };
    // Y
    int arrY[14][2] = {
    		{1,5},{1,9},{2,5},{2,9},{3,5},{3,9},{4,5},{4,6},{4,7},{4,8},
			{5,5},{6,6},{6,7},{6,8}
    };
    // Z
    int arrZ[13][2] = {
    		{2,5},{2,6},{2,7},{2,8},{2,9},{3,6},{4,7},{5,8},{6,5},{6,6},
			{6,7},{6,8},{6,9}
    };

    while (1)
    {
    	int c = 1000;
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 14; i++)
    		{
    			*GPIOA_ODR |= (1 << arrA[i][0]);
    			*GPIOB_ODR |= (1 << arrA[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrA[i][0]);
    			*GPIOB_ODR &= ~(1 << arrA[i][1]);
    		}
    	}
    	delay1();
       for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 16; i++)
    		{
    			*GPIOA_ODR |= (1 << arrB[i][0]);
    			*GPIOB_ODR |= (1 << arrB[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrB[i][0]);
    			*GPIOB_ODR &= ~(1 << arrB[i][1]);
    		}
    	}
    	delay1();
       for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 11; i++)
    		{
    			*GPIOA_ODR |= (1 << arrC[i][0]);
    			*GPIOB_ODR |= (1 << arrC[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrC[i][0]);
    			*GPIOB_ODR &= ~(1 << arrC[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 16; i++)
    		{
    			*GPIOA_ODR |= (1 << arrD[i][0]);
    			*GPIOB_ODR |= (1 << arrD[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrD[i][0]);
    			*GPIOB_ODR &= ~(1 << arrD[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 14; i++)
    		{
    			*GPIOA_ODR |= (1 << arrE[i][0]);
    			*GPIOB_ODR |= (1 << arrE[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrE[i][0]);
    			*GPIOB_ODR &= ~(1 << arrE[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 9; i++)
    		{
    			*GPIOA_ODR |= (1 << arrF[i][0]);
    			*GPIOB_ODR |= (1 << arrF[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrF[i][0]);
    			*GPIOB_ODR &= ~(1 << arrF[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 17; i++)
    		{
    			*GPIOA_ODR |= (1 << arrG[i][0]);
    			*GPIOB_ODR |= (1 << arrG[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrG[i][0]);
    			*GPIOB_ODR &= ~(1 << arrG[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 14; i++)
    		{
    			*GPIOA_ODR |= (1 << arrH[i][0]);
    			*GPIOB_ODR |= (1 << arrH[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrH[i][0]);
    			*GPIOB_ODR &= ~(1 << arrH[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 6; i++)
    		{
    			*GPIOA_ODR |= (1 << arrI[i][0]);
    			*GPIOB_ODR |= (1 << arrI[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrI[i][0]);
    			*GPIOB_ODR &= ~(1 << arrI[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 7; i++)
    		{
    			*GPIOA_ODR |= (1 << arrJ[i][0]);
    			*GPIOB_ODR |= (1 << arrJ[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrJ[i][0]);
    			*GPIOB_ODR &= ~(1 << arrJ[i][1]);
    		}
    	}
    	delay1();

    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 13; i++)
    		{
    			*GPIOA_ODR |= (1 << arrK[i][0]);
    			*GPIOB_ODR |= (1 << arrK[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrK[i][0]);
    			*GPIOB_ODR &= ~(1 << arrK[i][1]);
    		}
    	}
    	delay1();
       for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 7; i++)
    		{
    			*GPIOA_ODR |= (1 << arrL[i][0]);
    			*GPIOB_ODR |= (1 << arrL[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrL[i][0]);
    			*GPIOB_ODR &= ~(1 << arrL[i][1]);
    		}
    	}
    	delay1();
       for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 14; i++)
    		{
    			*GPIOA_ODR |= (1 << arrM[i][0]);
    			*GPIOB_ODR |= (1 << arrM[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrM[i][0]);
    			*GPIOB_ODR &= ~(1 << arrM[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 11; i++)
    		{
    			*GPIOA_ODR |= (1 << arrN[i][0]);
    			*GPIOB_ODR |= (1 << arrN[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrN[i][0]);
    			*GPIOB_ODR &= ~(1 << arrN[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 12; i++)
    		{
    			*GPIOA_ODR |= (1 << arrO[i][0]);
    			*GPIOB_ODR |= (1 << arrO[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrO[i][0]);
    			*GPIOB_ODR &= ~(1 << arrO[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 14; i++)
    		{
    			*GPIOA_ODR |= (1 << arrP[i][0]);
    			*GPIOB_ODR |= (1 << arrP[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrP[i][0]);
    			*GPIOB_ODR &= ~(1 << arrP[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 14; i++)
    		{
    			*GPIOA_ODR |= (1 << arrQ[i][0]);
    			*GPIOB_ODR |= (1 << arrQ[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrQ[i][0]);
    			*GPIOB_ODR &= ~(1 << arrQ[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 8; i++)
    		{
    			*GPIOA_ODR |= (1 << arrR[i][0]);
    			*GPIOB_ODR |= (1 << arrR[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrR[i][0]);
    			*GPIOB_ODR &= ~(1 << arrR[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 13; i++)
    		{
    			*GPIOA_ODR |= (1 << arrS[i][0]);
    			*GPIOB_ODR |= (1 << arrS[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrS[i][0]);
    			*GPIOB_ODR &= ~(1 << arrS[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 10; i++)
    		{
    			*GPIOA_ODR |= (1 << arrT[i][0]);
    			*GPIOB_ODR |= (1 << arrT[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrT[i][0]);
    			*GPIOB_ODR &= ~(1 << arrT[i][1]);
    		}
    	}
    	delay1();

    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 11; i++)
    		{
    			*GPIOA_ODR |= (1 << arrU[i][0]);
    			*GPIOB_ODR |= (1 << arrU[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrU[i][0]);
    			*GPIOB_ODR &= ~(1 << arrU[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 9; i++)
    		{
    			*GPIOA_ODR |= (1 << arrV[i][0]);
    			*GPIOB_ODR |= (1 << arrV[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrV[i][0]);
    			*GPIOB_ODR &= ~(1 << arrV[i][1]);
    		}
    	}
    	delay1();
       for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 14; i++)
    		{
    			*GPIOA_ODR |= (1 << arrW[i][0]);
    			*GPIOB_ODR |= (1 << arrW[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrW[i][0]);
    			*GPIOB_ODR &= ~(1 << arrW[i][1]);
    		}
    	}
    	delay1();
       for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 9; i++)
    		{
    			*GPIOA_ODR |= (1 << arrX[i][0]);
    			*GPIOB_ODR |= (1 << arrX[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrX[i][0]);
    			*GPIOB_ODR &= ~(1 << arrX[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 14; i++)
    		{
    			*GPIOA_ODR |= (1 << arrY[i][0]);
    			*GPIOB_ODR |= (1 << arrY[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrY[i][0]);
    			*GPIOB_ODR &= ~(1 << arrY[i][1]);
    		}
    	}
    	delay1();
    	for (j = 0; j < c; j++)
    	{
    		for (i = 0; i < 13; i++)
    		{
    			*GPIOA_ODR |= (1 << arrZ[i][0]);
    			*GPIOB_ODR |= (1 << arrZ[i][1]);
    			delay();
    			*GPIOA_ODR &= ~(1 << arrZ[i][0]);
    			*GPIOB_ODR &= ~(1 << arrZ[i][1]);
    		}
    	}
    	delay1();
    }
}

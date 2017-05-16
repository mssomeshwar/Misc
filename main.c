#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static uint8_t gsFreqIntegerPart[3] = {0};
static uint8_t gsFreqFracPart[3] = {0};

void updateCurrentFreq(int aIntPart, int aFracPart)
{
    int i = 0;
    int lIntPart = aIntPart;
    int lFracPart = aFracPart;

    for(i=0; i<3; i++)
    {
        if( ( aIntPart < 100 ) && ( i == 2 ) )
        {
            gsFreqIntegerPart[3-1-i] = 0;
        }
        else
        {
            gsFreqIntegerPart[3-1-i] = lIntPart % 10;
        }
        lIntPart /= 10;

        if( ( aFracPart < 100 ) && ( i == 2 ) )
        {
            gsFreqFracPart[3-1-i] = 0;
        }
        else
        {
            gsFreqFracPart[3-1-i] = lFracPart % 10;
        }
        lFracPart /= 10;
    }
}

int main()
{
    int i = 0;
    int lIntegerPart = 0;
	int lRemainder = 0;
    int64_t lFreq = 156025000;

    lIntegerPart = lFreq / 1000000;
	lRemainder = (lFreq % 1000000)/1000;

    printf("%d.%03d\n",lIntegerPart, lRemainder);

    updateCurrentFreq(lIntegerPart, lRemainder);

    for(i=0; i<3; i++)
    {
        printf("%d", gsFreqIntegerPart[i]);
    }
    printf(".");
    for(i=0; i<3; i++)
    {
        printf("%d", gsFreqFracPart[i]);
    }
    return 0;
}

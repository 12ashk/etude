#include<stdio.h>

int main(void)
{
    int i = 5, j;

    for(j = 0; j < 4; j++)
    {
        i /= 2;
        printf("%d", i);
    }
    return 0;
}


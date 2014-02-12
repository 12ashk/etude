#include<stdio.h>

int  main(void)
{
    int i1, i2;
    i1 = 4;
    i2 = 2;

    /*よい条件文の作り方*/
    if ((i1 != 0) && (i2 != 0))
    {
        printf("Both are not zero #1 \n");
    }
    else if(i1 && i2)
    {
        printf("Both are not zero #2 \n");
    }
    else if(i1 & i2)
    {
        printf("Both are not zero #3 \n");
    }

    return 0;
}


#include<stdio.h>

int main(void)
{
    int  integer; //実数部分
    float num, fraction; //小数部分

    num = 123.456;

    integer = num;
    fraction = num - integer;
    printf("%.3f = %d + %.3f\n", num, integer, fraction);

    return 0;
}


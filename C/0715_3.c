#include<stdio.h>

int main(void)
{
    int i;
    float exp = 1;
    float x, a = 1;
    scanf("%f", &x);
    for(i = 1; i < 100; i++){
        a *= x / i;
        exp += a;
    }
    printf("%f\n", exp);
    return 0;
}


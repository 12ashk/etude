#include<stdio.h>

long double fact(long double x);

int main(void)
{
    long double total, x;
    scanf("%Lf", &x);
    printf("%Lf\n", fact(x));
    return 0;
}

long double fact(long double x)
{
    if(x == 1){
        return 1;
    } else{
        return fact(x-1) * x;
    }
}

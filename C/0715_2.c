#include<stdio.h>

int main(void)
{
    float x = 1.0, total = 0.0;
    int i;
    for(i = 0; i < 100; i++){
        x /= 2;
        total += x;
    }
    printf("%f\n", total);
    return 0;
}

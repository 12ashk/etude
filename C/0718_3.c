#include<stdio.h>

float fact(float i);

int main(void)
{
    float i;
    scanf("%f", &i);
    printf("%.1f\n", fact(i));

    return 0;
}

float fact(float i)
{
    if(i == 1){
        return 1;
    } else{
        return i * fact(i-1);
    }
}


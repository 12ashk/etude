#include<stdio.h>

int main(void)
{
    int i;
    float height[5], max;
    for(i = 0; i < 5; i++){
        scanf("%f", &height[i]);
    }
    for(i = 0, max = 0; i < 5; i++){
        if(height[i] > max){
            max = height[i];
        }
    }
    printf("%f\n", max);
    return 0;
} 

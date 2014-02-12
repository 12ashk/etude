#include<stdio.h>

int main(void)
{
    int i, N;
    float v[N], w[N], total = 0;
    scanf("%d", &N);
    printf("v?\n");
    for(i = 0; i < N; i++){
        scanf("%f", &v[i]);
    }
    printf("w?\n");
    for(i = 0; i < N; i++){
        scanf("%f", &w[i]);
    } 
    for(i = 0; i < N; i++){
        total += w[i] * v[i];
    }
    printf("inner product: %.2f\n", total);
    return 0;
}


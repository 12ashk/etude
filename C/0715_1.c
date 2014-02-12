#include<stdio.h>

int main(void)
{
    int num[5], i, j, temp;

    for(i = 0; i < 5; i++){
        scanf("%d", &num[i]);
    }
    for(i--; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(num[j] > num[j+1]){
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
    for(i = 0; i < 5; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}

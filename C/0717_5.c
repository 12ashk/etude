#include<stdio.h>

#define ARRAY_SIZE 10 //配列中の文字数

char array[ARRAY_SIZE] = "0123456789";

int main(void)
{
    int index; //配列のインデックス

    for(index = 0; index < ARRAY_SIZE; index++){
        printf("&array[index] = 0x%p (array + index) = 0x%p array[index] = 0x%x\n",
                &array[index], (array + index), array[index]);
    }

    return 0;
}


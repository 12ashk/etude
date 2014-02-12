#include<stdio.h>

int array[] = {3, 2, 2, 3, 4, 0, 6, 7, 8, 9};
int index;

int main(void)
{
    index = 0;
    while(array[index] != 0){
        index++;
    }

    printf("Number of elements before zero %d\n", index);
    return 0;
}


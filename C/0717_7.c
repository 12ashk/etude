#include<stdio.h>

int array[] = {4, 5, 6, 1, 0, 6, 3, 2, 1, 9};
int *array_ptr;

int main(void)
{
    array_ptr = array;
    while(*array_ptr != 0){
        array_ptr++;
    }

    printf("Number of elements before zero %d\n, %d", array_ptr - array);
    return 0;
}


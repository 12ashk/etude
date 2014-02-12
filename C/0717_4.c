#include<stdio.h>

void int_count(int *cout_ptr){
    ++(*count_ptr);
}

int main(void)
{
    int count = 0;
    while(count < 10){
        inc_count(&count);
    }

    return 0;
}


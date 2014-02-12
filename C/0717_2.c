#include<stdio.h>

int main(void)
{
    int i;
    typedef int group[10];
    group totals;
    for(i = 0; i < 10; i++){
        totals[i] = 0;
    }
    return 0;
}

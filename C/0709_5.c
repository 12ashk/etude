#include<stdio.h>

union value
{
    long int i_value;
    float f_value;
};

int i;
float f;

int main(void)
{
    union value data;

    data.i_value = 3;
    i = data.i_value;
    f = data.f_value;
    data.f_value = 5.5;
    i = data.i_value;
    return 0;
}

    

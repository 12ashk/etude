#include<stdio.h>

union value{
    long int i_value;
    float f_value;
};

int main(void)
{
    int i;
    float f;
    union value data;
    data.i_value = 3;
    i = data.i_value;
    f = data.f_value;
    data.f_value = 5.5;
    i = data.i_value;
    printf("%ld %f\n", data.i_value, data.f_value);
    return 0;
}

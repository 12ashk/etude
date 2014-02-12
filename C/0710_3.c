#include<stdio.h>

// float dismal -> binary 書きかけ
int binary(int i, int x[]);

int main(void)
{
    int exp[8] = {0};
    int temp[23] = {0};
    int  temporary[23] = {0};
    int  integer; // exp: 指数部数 temp:n 仮数数 temporary: 一時収納場場所 integer: 整数部
    int sign= 0, i, j, k; // sign: 正負
    long double num, div, fraction; //num: 入力数 div: 割る数 fraction: 小数部

    scanf("%Lf", &num);
    integer = num;
    fraction = num - integer;

    if(num == 0)
    {
    }
    else if(num < 0)
    {
        printf("error\n");
    }
    else if(num > 1)
    {
        for(i = 0; integer > 0; i++) //整数部を計算
        {
            temporary[i] = (integer % 2);
            integer /= 2;
        }
        k = i;
        for(i--, j = 0; i >= 0; i--, j++) //順番を直す
        {
            temp[j] = temporary[i];
        }
        for(i = 7, j += 127 - 1; j > 0 && i >= 0; i--)
        {
            exp[i] = (j % 2);
            j /= 2; 
        }
        for(i = 0, div = 1; fraction > 0 && (k + i) < 23; i++)
        {
            div /= 2;
            if(fraction >= div)
            {   
                temp[k+i] = 1;
                fraction -= div;
            }
        }
    }
    else
    {
        for(i = 0, div = 1; i < 127; i++)
        {
            div /= 2;
            if(fraction >= div)
            {
                fraction -= div;
                break;
            }
        }
        i++;
        for(i = 127 - i, j = 7; i > 0 && j >= 0; j--)
        {
            exp[j] = (i % 2);
            i /= 2;
        }
        for(i = 0; fraction > 0 && i < 23; i++)
        {
            div /= 2;
            if(fraction >= div)
            {
                temp[i] = 1;
                fraction -= div;
            }
        } 
    }

    printf("%d ", sign);
    for(i = 0; i < 8; i++)
    {
        printf("%d", exp[i]);
    }
    printf(" ");
    for(i = 0; i < 23; i++)
    {
        printf("%d", temp[i]);
    }
    printf("\n");
    return 0;
}


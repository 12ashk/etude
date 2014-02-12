#include<stdio.h>
#define N 100

int main(void)
{
  int i , j, n, x[N];

  scanf("%d", &n);

  for(i = 0; n > 0; i++)
    {
      x[i] = n % 10;
      n /= 10;
    }

  for(n = 1, i--, j = 1; i > -1; i--)
    {
      n += x[i] * j;
      j *= 2;
    }

  printf("%d\n", n);

  return 0;
}

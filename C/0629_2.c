#include<stdio.h>
#define N 10000

int main(void)
{
  int i, j, n, x[N];

  for(i = 0; i < N; i++)
    {
      scanf("%d", &x[i]);
      if(x[i] != 0 && x[i] != 1)
	{
	  break;
	}
    }

  for(j = 0, n = 1, i--; i > -1; i--)
    {
      j += x[i] * n;
      n *= 2;
    }

  printf("%d\n", j);

  return 0;
}

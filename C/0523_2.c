#include<stdio.h>
#define N 5

int main(void)
{
  int i, result, v[5], w[5];

  printf("v?\n");
  for(i = 0; i < 5; i++)
    {
      scanf("%d", &v[i]);
    }

  printf("w?\n");
  for(i = 0; i < 5; i++)
    {
      scanf("%d", &w[i]);
    }
  for(i = 0, result = 0; i < 5; i++)
    {
      result = result + v[i] * w[i];
    }

  printf("inner product: %d\n", result);

  return 0;
}

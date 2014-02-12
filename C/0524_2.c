#include<stdio.h>

int main(void)
{
  int x[5] = {30, 25, 33, 12, 22};
  int *p, i;

  p = x;
  printf("%d\n", *p);

  for(i = 0; i < 5; i++)
    {
      printf("%d\n", * (p + i));
    }

  return 0;
}

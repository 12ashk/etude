#include<stdio.h>

int main(void)
{
  int a, b, c;

  for(a = 0, b = 1; b < 10;)
    {
      printf("%d ", b);
      c = b;
      b = a + b;
      a = c;
    }

  printf("\n");

  return 0;
}

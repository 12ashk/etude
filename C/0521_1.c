#include<stdio.h>

void main(void)
{
  int i, n = 3;
  int func1(int n);
  int func2(int n);

  for(i = 0; i < n; i++)
    {
      printf("%d\n", func1(n));
      printf("%d\n", func2(n));
    }
}

int func1(int n)
{
  int i = 0;

  i += n;
  return i;
}

int func2(int n)
{
  static int i;

  i += n;
  return i;
}

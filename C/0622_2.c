#include<stdio.h>

int main(void)
{
  int i, n = 1024;

  for(i = 0; n > 1; i++)
    {
      n =  n/ 2;
    }

  printf("%d\n", i);

  return 0;
}

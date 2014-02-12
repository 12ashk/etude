#include<stdio.h>

int main(void)
{
  char x[3][10];
  char *p[3];
  int i;

  for(i = 0; i < 3; i++)
    {
      p[i] = x[i];
    }

  for(i = 0; i < 3; i++)
    {
      gets(x[i]);
    }

  for(i = 0; i < 3; i++)
    {
      printf("%d, %s\n", i, p[i]);
    }

  return 0;

}

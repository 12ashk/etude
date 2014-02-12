#include<stdio.h>

int main(void)
{
  int i, a[] = { 1, 1, 1, 0, 0, 1, 0, 1};

  for(i = 0; i <8; i++)
    {
      if(a[i] == 0)
	{
	  a[i] = 1;
	}
      else
	{
	  a[i] = 0;
	}
    }

  for(i = 0; i < 8; i++)
    {
      printf("%d ", a[i]);
    }
  printf("\n");

  return 0;
}

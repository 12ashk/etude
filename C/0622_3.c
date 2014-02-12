#include<stdio.h>

int main(void)
{
  int num, i = 1, n = 0;

  while(1)
    {
      num *= 2;
      n++;
      if(num == 1024)
	{
	  break;
	}
    }

  return 0;
}

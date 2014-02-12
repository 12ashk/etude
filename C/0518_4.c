#include<stdio.h>

int main(void)
{
  int i, c;

  i = 1;

  for(; ;i++)
    {
      scanf("%d",&c);

      if(c == (-1))
	{
	  break;
	}
      else if(c <= 32 || 127 <= c)
	{
	  continue;
	}
      else
	{
	  printf("%d : %x = %c\n", i, c, c);
	}
    }

  return 0;
}

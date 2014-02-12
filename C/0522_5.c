#include<stdio.h>

int main(void)
{
  int a[2][2][2];
  int i, j, k;

  printf("a         =%x\n",a);

  for(i = 0; i < 2; i++)
    {
      printf("a[%d]      =%x\n", i, &a[i]);

      for(j = 0; j < 2; j++)
	{
	  printf("a[%d][%d]   =%x\n", i, j, &a[i][j]);

	  for(k = 0; k < 2; k++)
	    {
	      printf("a[%d][%d][%d]=%x\n", i, j, k, &a[i][j][k]);
	    }
	}
    }

  return 0;
}

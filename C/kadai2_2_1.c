#include<stdio.h>

int main(void)
{
  int i, j, l, k;
  int a[3][3] = {{1, 3, 2}, {7, 1, 9}, {10, 5, 0}};
  int b[3][3] = {{2, 11, 3}, {8, 3, 2}, {9, 3, 4}};

  printf("AB =\n");
  for(i = 0; i < 3; i++)
    {      
      for(j = 0, l = 0; j < 3; j++, l = 0)
	{
	  for(k = 0; k < 3; k++)
	    {
	      l += a[i][k] * b[k][j];
	    }
	  printf("%5d", l);
	}
      printf("\n");
    }

  return 0;
}

#include<stdio.h>

int main(void)
{
  int i,j;
  double height[2][5] = {{160.0, 170.0, 180.7, 180.5, 180.0},
			 {160.0, 158.0, 155.8, 170.0, 151.0}};
  double total = 0.0;

  for(i = 0; i < 2; i++, total = 0.0)
    {
      for(j = 0; j < 5; j++)
	{
	  total += height[i][j];
	}

      	  printf("%d:%.2f\n", i+1, total / j);
    }

  return 0;
}

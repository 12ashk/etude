#include<stdio.h>

int main(void)
{
  int i;
  float height[5] = {175.2, 182.6, 166.5, 167.8, 170.0};
  float max = 0;
  for(i = 0; i < 5; i++)
    {
      if(height[i] > max)
	{
	  max = height[i];
	    }
    }

  printf("max = %.1f\n", max);

  return 0;
}

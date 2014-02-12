#include<stdio.h>

int main(void)
{
  int i;
  double height [5] = {160.0, 170.0, 146.7, 180.5, 180.0};
  double total = 0.0;

  for(i = 0; i < 5; i++)
    {
      total += height[i];
    }

  printf("%.1f\n", total/5);

  return 0;
}

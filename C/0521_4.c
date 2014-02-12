#include<stdio.h>

float height[100];

float average(int max);

int main(void)
{
  int cnt = 0;
  float h;

  scanf("%f",&h);

  while((cnt < 100) && (h > 0.0))
    {
      height[cnt] = h;
      cnt++;
      scanf("%f",&h);
    }

  printf("%5.2f\n", average(cnt));

  return 0;
}

float average(int max)
{
  int i;
  float total = 0.0;

  for(i = 0; i < max; i++)
    {
      total += height[i];
    }

  return total / max;
}

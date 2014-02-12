#include<stdio.h>

double ave(float x, float y);

int main(void)
{
  float x, y;
  double ret;

  printf("input x:");
  scanf("%f",&x);
  printf("input y:");
  scanf("%f",&y);

  ret = ave(x, y);

  printf("ave = %f\n",ret);

  return 0;
}

double ave(float x, float y)
{
  return (double)(x + y) / 2;
}

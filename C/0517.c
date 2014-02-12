#include<stdio.h>

int main(void)
{
  float x,y,n,total;

  total=1;
  x=1;
  y=1;

  scanf("%f",&x);

  for(n=1;n<100;n++)
    {
      y=y*x/n;
      total=total+y;
    }

  printf("%f\n",total);

  return 0;
}

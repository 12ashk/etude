#include<stdio.h>

int main(void)
{
  float x= 1;
  float total = 0.0;
  float m;
  int i;

  scanf("%f",&m);

  for(i=0; i<m; i++)
    {
      x /= 2;
      total += x;
    }

  printf("%f\n",total);
  return 0;
}

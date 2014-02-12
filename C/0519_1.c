#include<stdio.h>

int kaijo(int n);

int main(void)
{
  int x, ret;

  scanf("%d",&x);

  ret = kaijo(x);

  printf("kaijo = %d\n",ret);

  return 0;
}

int kaijo(int n)
{
  if(n == 0)
    {
      return 1;
    }
  else
    {
      return n * kaijo(n-1);
    }
}

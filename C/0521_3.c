#include<stdio.h>

int main(void)
{
  int i, x;
  int a [5] = {10, 20, 30, 40, 50};

  scanf("%d",&x);

  a [2] = x;

  for(i = 0; i < 5; i++)
  {
    printf("a[%d] = %d\n", i+1, a[i]);
  }

  return 0;
}

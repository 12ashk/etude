#include<stdio.h>

int main(void)
{
  int a1[5] = {50, 80, 20, 30, 10};
  int b1[5] = {20, 40, 30, 20, 50};
  int *p[2];
  int i;
  int ave;

  p[0] = a1;
  p[1] = b1;
  for(i = 0; i < 5; i++)
    {
      ave = (*(p[0] + i) + *(p[1] + i)) / 2;
      printf("%d,%d\n", i, ave);
    }

  return 0;
}

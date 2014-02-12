#include<stdio.h>

int main(void)
{
  int x;
  int *p;

  scanf("%d", &x);
  p = &x;
  printf("%d,%d,%x,%x\n", x, *p, &x, p);

  return 0;
}

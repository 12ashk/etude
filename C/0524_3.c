#include<stdio.h>

int main(void)
{
  int n[2] = {10 ,20};
  int *p = n, m;

  printf("%x\n", p);

  m = *p++;
  printf("%d,%x\n", m, p);

  return 0;
}


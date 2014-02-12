#include<stdio.h>

int add(int n);

int main(void)
{
  int i = 1;

  printf("1:%d,%X\n", i, &i);
  i = add(i);
  printf("2:%i,%x\n", i, &i);
  i = add(i);
  printf("3:%d,%x\n", i, &i);

  return 0;
}

int add(int n)
{
  int i = 0;

  printf("f:%d,%x\n", i, &i);
  i += n;

  return i;
}

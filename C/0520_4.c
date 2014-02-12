#include<stdio.h>

static int n;

void add(int i);
void multi(int r);

int main(void)
{
  int i = 1;

  add(i);
  multi(i);
  printf("1:%d,%d\n", i ,n);
  add(i);
  multi(i);
  printf("2:%d,%d\n", i, n);

  return 0;
}

void add(int i)
{
  n += i;
}

void multi(int r)
{
  n *=r;
}

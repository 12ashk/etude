#include<stdio.h>

int main(void)
{
  int a;
  float b;
  double c;
  long double d;

  printf("%u %u %u %u\n", sizeof a, sizeof b, sizeof c, sizeof d);

  return 0;
}

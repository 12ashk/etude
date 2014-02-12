#include<stdio.h>

long int nadd(void);

int main(void)
{
  long int ret;

  ret  = nadd();
  printf("%ld\n",ret);

  return 0;
}

long int nadd(void)
{
  register long int i, n = 0;

  for(i = 1; i <= 30000; n += i, i++);

  return n;
}

#include<stdio.h>

static long int n;

int main(void)
{
  int i, m;

  scanf("%ld", &n);

  for(i = 1, m = n; i < m; i++)
    {
      n *= (m - i);
    }
  
  printf("%ld\n", n);
  
  return 0;
}

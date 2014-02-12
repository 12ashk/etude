#include<stdio.h>
#define x double

static x n;

void fact(x m);

int main(void)
{
  x m;
  scanf("%lf", &m);
  fact(m);
  printf("%lf\n", n);

  return 0;
}

void fact(x m)
{
  int i;
   n = m;

   for(i = 1; i < m; i++)
    {
      n *= (m - i);
    }
}

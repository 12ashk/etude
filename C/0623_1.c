#include<stdio.h>

//disimal -> binary

int main(void)
{
  int i, j, n, m[1000];
  
  scanf("%d", &n);
  
  for(i = 0; n > 0; i++)
    {
      m[i] = (n % 2);
      n /= 2;
    }
  
  for(i -= 1 ; i != -1; i--)
    {
      printf("%d", m[i]);
    }
  
  printf("\n");
  
  return 0;
}

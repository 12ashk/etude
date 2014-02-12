#include<stdio.h>

int main(void)
{
  int i, j, ln;

  scanf("%d",&ln);

  for(i = 0; i < ln; i++)
  {
    for(j = 0; j <= i; j++)
    {
      printf("*");
    }

    printf("\n");
  }

  return 0;
}

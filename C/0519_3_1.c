#include<stdio.h>

int main(void)
{
  int i, j, width;

  scanf("%d",&width);

  for(i = 0; i < width; i++)
  {
    for(j = 0; j < width; j++)
    {
      printf("*");
    }

    printf("\n");
  }

  return 0;
}

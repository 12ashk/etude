#include<stdio.h>

int main(void)
{
  int i, j, width, height;

  printf("width:");
  scanf("%d",&width);
  printf("heightl:");
  scanf("%d",&height);

  for(i = 0; i < height; i++)
  {
    for(j = 0; j < width; j++)
    {
      printf("*");
    }

    printf("\n");
  }

  return 0;
}

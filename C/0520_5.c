#include<stdio.h>

int main(void)
{
  int i =1;

  printf("ob:%d\n", i);
  i++;

  {
    int i = 10;
    printf("ib:%d\n", i);
    i++;
    
    {
      int i = 100;
      printf("i:%d\n", i);
    }

    printf("ia:%d\n", i);
  }

  printf("oa:%d\n", i);

  return 0;
}

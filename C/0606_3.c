#include<stdio.h>

struct gstudent
{
  char  name[20];
  int   height;
  float weight;
  long  schols;
};

int main(void)
{
  struct gstudent sanaka = {"sanaka", 175, 60.5};

  printf("name = %s\n", sanaka.name);

  return 0;
}

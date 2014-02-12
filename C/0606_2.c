#include<stdio.h>
#include<string.h>

struct gstudent
{
  char  name[20];
  int   height;
  float weight;
  long  schols;
};

int main(void)
{
  struct gstudent sanaka;


  strcpy(sanaka.name, "sanaka");
  sanaka.height = 175;
  sanaka.weight = 60.5;
  sanaka.schols = 70000;

  printf("name = %s\n", sanaka.name);

  return 0;
}

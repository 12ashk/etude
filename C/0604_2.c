#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  double ave;

  printf("command name       : %s\n", argv[0]);
  printf("number of arguments: %d\n", argc);

  ave = (atof(argv[1]) + atof(argv[2])) / 2;
  printf("ave = %f\n", ave);

  return 0;
}

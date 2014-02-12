#include <stdio.h>

#define N 6

int main()
{
  struct PERSON
  {
    char family_name[20];
    char given_name[20];
    float height;
    float weight;
  } p[N];
  int i;
  FILE *fp;

  fp=fopen("data09.txt", "r");
  for (i=0; i<N; i++)
  {
    fscanf(fp, "%s", p[i].given_name);
    fscanf(fp, "%s", p[i].family_name);
    fscanf(fp, "%f", &p[i].height);
    fscanf(fp, "%f", &p[i].weight);
  }
  fclose(fp);

  for (i=0; i<N; i++)
  {
    printf("%s %s %f %f\n", p[i].given_name, p[i].family_name, p[i].height, p[i].weight);
  }

  return 0;
}
    

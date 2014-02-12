#include<stdio.h>

int main(void)
{
  char str1[5] = "abcd";
  char str2[5] = "opqr";
  char str3[9];
  int j = 0;
  int i = 0;

  for(; str1[i] != '\0'; i++, j++)
    {
      str3[j] = str1[i];
    }

  for(i = 0; str2[i] != '\0'; i++, j++)
    {
      str3[j] = str2[i];
    }

  str3[j] = '\0';
  printf("%s\n",str3);

  return 0;
}

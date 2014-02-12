#include<stdio.h>

int main(void)
{
  int i, j, l, k;
  int a[3][3] = {{1, 3, 2}, {7, 1, 9}, {10, 5, 0}};
  int b[3][3] = {{2, 11, 3}, {8, 3, 2}, {9, 3, 4}};
  int c[3][3] = { 0 };

  for(i = 0; i < 3; i++)
    {
      for(j = 0, l =0; j < 3; j++)
	{
	  for(k = 0; k < 3; k++)
	    {
     

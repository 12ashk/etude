#include<stdio.h>
#define MAXLENGTH 2000

char genome[MAXLENGTH];

int main(void)
{
  int i, j, k;
  FILE *infogenome; 
  
  infogenome = fopen("genome-seq.data", "r");
  fscanf(infogenome, "%s", genome); 
  fclose(infogenome);
  
  for(i = 0; genome[i] != '\0'; i++)
    {
      if(genome[i] == 'A' && genome[i+1] == 'T' && genome[i+2] == 'G')
	{
	  for(j = i; genome[i] != '\0'; i++)
	    {
	      for(; (i - j + 1) % 3 != 0 || genome[i-2] != 'T' 
		    || genome[i-1] != 'G' || genome[i] != 'A'; i++)
		{
		  printf("%c", genome[i]);
		  if(genome[i] == '\0')
		    {
		      break;
		    }
		}
	      printf("\n");
	      printf("gene candidate region: from %d to %d\n\n", j + 1, i+ 1);
	      
	      for(k = j; k <= i; k++)
		{
		  printf("%c", genome[k]);
		}
	    }
	}
    } 
  return 0;
}

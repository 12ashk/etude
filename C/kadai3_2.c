/*ORFprint program*/
#include<stdio.h>
#define MAXLENGTH 2000

char genome[MAXLENGTH]; //file to read

int main(int argc, char argv[])
{
    int i, j, k;
    FILE *infogenome; //DNA file

    infogenome = fopen("genome-seq.data", "r");
    if(infogenome == '\0'){
    } else {
        fscanf(infogenome, "%s", genome); //load genome
        fclose(infogenome);
        for(i = 0; genome[i] != '\0'; i++){
            if(genome[i] == 'A' && genome[i+1] == 'T' && genome[i+2] == 'G'){
                for(j = i; genome[i] != '\0'; i++){
                    if((i - j + 1) % 3 == 0 && genome[i-2] == 'T'
                            && genome[i-1] == 'G' && genome[i] == 'A'){
                        printf("gene candidate region: from %d to %d\n", j + 1, i);
                        for(k = j; k <= i; k++){
                            printf("%c", genome[k]);
                        }
                        printf("\n\n");
                    }
                }
                i = j;
            }
        }
    }
    return 0;
}

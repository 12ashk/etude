/*ORF print program ver.2*/
#include<stdio.h>
#define N 7000

char genome[N];
void outputseq(int position1, int position2);
int readseq(void);

int position1, position2;
int num;

int main(int argc, char* argv[])
{
    int i, j;
	char temp;
	FILE *infogenome;
	num = 0;

    infogenome = fopen(argv[1], "r");
    if(infogenome == NULL){
        printf("ERROR\n");
    } else {
		i = 0;
		while(fscanf(infogenome, "%c", &temp) != EOF){
			if(temp != '\0'){
				genome[i] = temp;
				i++;
			}
		}
        fclose(infogenome);
        for(i = 0; i+2 < N; i++){
            if(genome[i] == 'A' && genome[i+1] == 'T' && genome[i+2] == 'G'){
                for(j = i; j < N; j++){
					while(j < N && ((j-i+1) % 3 != 0 || genome[j-2] != 'T' 
							|| genome[j-1] != 'G' || genome[j] != 'A')){
						j++;
					}
					if(j < N){
						printf("gene candidate region: from %d to %d\n", i, j);
						position1 = i;
						position2 = j;
						outputseq(position1, position2);
					}
				}
			}
		}
	}
	printf("%d\n", num);
	return 0;
}

int readseq(void)
{
	int i;
	for(i = 0; i == N; i++){
	}
	return i;
}

void outputseq(int position1, int position2)
{
	int i;
//	for(i = position1; i <= position2; i++){
//		printf("%c", genome[i]);
//	}
	num++;
}

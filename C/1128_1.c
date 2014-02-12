#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 7000

int main(int argv, char *argc[])
{
	srand(time(NULL));
	int A, T, G, C;
	int i;
	double t, pA, pT, pG, pC;
	char temp;
	char seq[N];

	FILE *file;
	file = fopen(argc[1], "r");

	A = 0;
	T = 0;
	G = 0;
	C = 0;
	int inum = 0;
	while(fscanf(file, "%c", &temp) != EOF){
		if(temp != '\n'){
			inum++;
		}
		if(temp == 'A'){
			A++;
		}
		else if(temp == 'T'){
			T++;
		}
		else if(temp == 'G'){
			G++;
		}
		else if(temp == 'C'){
			C++;
		}
	}
	fclose(file);
	pA = (double) A / inum;
	pT = (double) T / inum;
	pG = (double) G / inum;
	pC = (double) C / inum;
	printf("A: %.1lf%%\nT: %.1lf%%\nG: %.1lf%%\nC: %.1lf%%\n",
			100*pA, 100*pT, 100*pG, 100*pC);
	
	A = 0;
	T = 0;
	C = 0;
	G = 0;
	for(inum = 0; inum < N; inum++){
		t = (double) rand()/ RAND_MAX;
		if(0 <= t && t <= pA){
			seq[inum] = 'A';
			A++;
		}
		else if(pA < t && t <= pA + pT){
			seq[inum] = 'T';
			T++;
		}
		else if(pA + pT < t && t <= pA + pT + pG){
			seq[inum] = 'G';
			G++;
		}
		else{
			seq[inum] = 'C';
			C++;
		}
	}
	inum -= 1;	
	pA = (double) 100 * A / inum;
	pT = (double) 100 * T / inum;
	pG = (double) 100 * G / inum;
	pC = (double) 100 * C / inum;
	printf("\nA: %.1lf%%\nT: %.1lf%%\nG: %.1lf%%\nC: %.1lf%%\n"
			, pA, pT, pG, pC);
	FILE *pfile;
	pfile = fopen(argc[2], "w");
	for(i = 0; i < inum; i++){
		fprintf(pfile, "%c", seq[i]);
	}
	fclose(pfile);

	return 0;
}

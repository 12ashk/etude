/* merge sort */
#include<stdio.h>
#define max 100000

void msort(int A[], int p, int q);
void merge(int A[], int a, int b, int c, int d);

int main(int argc, char *argv[])
{
	int A[max];
	int i, inum;
	FILE *file;

	file = fopen(argv[1], "r");
	inum = 0;
	while(fscanf(file, "%d", &A[inum]) != EOF){
			inum++;
	}
	fclose(file);

	msort(A, 0, inum-1);
	
	for(i = 0; i < inum; i++){
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}

void msort(int A[], int p, int q)
/* array, first of array, last of array */
{
	int x;
	if(p < q){
		x = (q+1-p)/2 + p-1;
		msort(A, p, x); //first half
		msort(A, x+1, q); //latter half
		merge(A, p, x, x+1, q);
	}
}

void merge(int A[], int a, int b, int c, int d)
/* array, first of FH, last of FH, first of LH, last of LH) */
{
	int temp[max], t, l, mlen;
	t = a;
	mlen = (b-a+1) + (d-c+1);
	for(l = 0; c <= d && a <= b; l++){
		if(A[a] < A[c]){
			temp[l] = A[a];
			a++;
		}
		else{
			temp[l] = A[c];
			c++;
		}
	}
	for(; l < mlen; l++){
		if(c > d){
			temp[l] = A[a];
			a++;
		}
		else{
			temp[l] = A[c];
			c++;
		}
	}

	for(l = 0; l < mlen; l++){
		A[t+l] = temp[l];
	}
}

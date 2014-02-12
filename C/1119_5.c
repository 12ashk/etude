/* quick sort by array random selection */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 10000

void myqsort(int A[], int p, int q);
int partition(int A[], int p, int q);

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int A[max];
	int inum, i;
	FILE *file;
	file = fopen(argv[1], "r");
	inum = 0;
	while(fscanf(file, "%d", &A[inum]) != EOF){
		inum++;
	}
	fclose(file);

	myqsort(A, 0, inum-1);
	for(i = 0; i < inum; i++){
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}

void myqsort(int A[], int p, int q)
{
	if(p < q){
		int r;
		r = partition(A, p, q);
		myqsort(A, p, r);
		myqsort(A, r+1, q);
	}
}

int partition(int A[], int p, int q)
{
	int i, j, t;
	float pivot;
	if(p+1 == q && A[p] <= A[q]){
		return p;
	}
	else if(p+1 == q && A[p] > A[q]){
		t = A[p];
		A[p] = A[q];
		A[q] = t;
		return p;
	}
	pivot = (A[p] + A[q] + A[(p+q)/2])/3;
	i = p;
	j = q;
	while(i < j){
		while(i < j && A[j] >= pivot){
			j--;
		}
		while(i < j && A[i] < pivot){
			i++;
		}
		if(i < j){
			t = A[i];
			A[i] = A[j];
			A[j] = t;
			i++;
			j--;
		}
	}
	if(i == j && A[i] < pivot){
		return i;
	}
	else{
		return j;
	}
}

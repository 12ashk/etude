/* quick sort by array */
#include<stdio.h>
#define max 10000

void qsort(int A[], int p, int q);
int partition(int A[], int p, int q);

int main(int argc, char *argv[])
{
	int A[max];
	int inum, i;
	FILE *file;

	file = fopen(argv[1], "r");
	inum = 0;
	while(fscanf(file, "%d", &A[inum]) != EOF){
		inum++;
	}
	fclose(file);

	qsort(A, 0, inum-1);
	for(i = 0; i < inum; i++){
		printf("%d ", A[i]);
	}
	printf("\n");

	return 0;
}

void qsort(int A[], int p, int q)
{
	if(p < q){
		int r;
		r = partition(A, p, q);
		qsort(A, p, r);
		qsort(A, r+1, q);
	}
}

int partition(int A[], int p, int q)
{
	int i, j, t, pivot;
	pivot = A[p];
	i = 0;
	do{
		i++;
		if(A[p+i] > pivot){
			pivot = A[p+i];
			break;
		}
	}while(A[p+i] == pivot && p+i != q);
	if(p+i == q){
		return p;
	}
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

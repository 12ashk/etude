/* bubble sort */
#include<stdio.h>
#define max 1000000

void bsort(int A[], int q);

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

	bsort(A, inum-1);
	
	return 0;
}

void bsort(int A[], int num)
{
	int i, j, temp;
	for(i = num; i > 0; i--){
	   for(j = 0; j < i; j++){
		   if(A[j+1] < A[j]){
			   temp = A[j];
			   A[j] = A[j+1];
			   A[j+1] = temp;
		   }
	   }
	}
}

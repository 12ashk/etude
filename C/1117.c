#include<stdio.h>
#define N 2147483647
#define MAX 100000

int A[MAX];

void makeheap(int i);
int hsort(int i);
int findparent(int i);

int main(int argc, char *argv[])
{
	int n, i;//number of data
	FILE *file;
	file = fopen(argv[1], "r");
	fscanf(file, "%d", &A[0]);
	i = 1;
	for(i = 0; ; i++){
		if(fscanf(file, "%d", &A[i]) == EOF){
			A[i] = 0;
			i--;
			break;
		}
		makeheap(i);
	}

	hsort(i-1);

	return 0;
}

void makeheap(int i)
{
	int l, temp;
	l = findparent(i);
	while(1){
		if(A[i] < A[l]){
			temp = A[i];
			A[i] = A[l];
			A[l] = temp;
			i = l;
			l = findparent(l);
		}
		else{
			break;
		}
	}
}

int findparent(int i)
{
	int l;
	if((i % 2) == 0){
		l = (i / 2) - 1;
	}
	else{
		l = ((i + 1) / 2) - 1;
	}
	return l;
}

int hsort(int n)
{
	if(n == 1){
		if(A[0] < A[1]){
			printf("%d %d\n", A[0], A[1]);
		}
		else{
			printf("%d %d\n", A[1], A[0]);
		}
		return 0;
	}
	else{
		printf("%d ", A[0]);
		int i = 0, j = 1, temp;
		A[0] = A[n];
		A[n] = 0;
		while(1){
			if((A[i] <= A[j] && A[i] <= A[j+1])
					|| i >= n - 1 || A[j+1] == 0){
				break;
			}
			else if(A[j] < A[j+1] && A[j] != 0){
				temp = A[j];
				A[j] = A[i];
				A[i] = temp;
				i = j;
				j = j * 2 + 1;
			}
			else{
				temp = A[j+1];
				A[j+1] = A[i];
				A[i] = temp;
				i = j + 1;
				j = j  * 2 + 3;
			}
		}
		n--;
		hsort(n);
	}
	return 0;
}


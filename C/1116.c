#include<stdio.h>
#define N 2147483647
#define MAX 100000

int A[MAX];

void makeheap(int n);
int hsort(int i);
int findparent(int i);

int main(void)
{
	int n;//number of data
	int i, j;
	printf("input number of data: ");
	scanf("%d", &n);
	makeheap(n);

	hsort(n-1);

	return 0;
}

void makeheap(int n)
{
	int i, j, k, l, temp;
	//i = counter, j = number of last leaves, k = number of data
	for(i = 0; i < n; i++){
		printf("input data: ");
		scanf("%d", &A[i]);
		k = i;
		l = findparent(i);
		while(1){
			if(A[k] < A[l]){
				temp = A[k];
				A[k] = A[l];
				A[l] = temp;
				k = l;
				l = findparent(l);
			}
			else{
				break;
			}
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
	if(n == 0){
		printf("%d\n", A[0]);
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


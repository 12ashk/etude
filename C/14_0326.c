#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<math.h>
#define N 100000000

int full_search1(int *array, int n, int t)
{
	int i, j, k, l;
	for(i = 0; i < n; i++){
		for(j = i; j < n; j++){
			for(k = j; k < n; k++){
				for(l = k; l < n; l++){
					long temp = array[i]+array[j]+array[k]+array[l];
					if(temp < N){
						if(temp == t) return 0;
					}	
				}
			}
		}
	}
	return 1;
}

int full_search2(int *array, int n, int t)
{
	int i, j, k, l, max;
	long temp;
	max = array[n-1];
	if(max > t){
		if(max*4 < t) return 1;
		for(i = 0; array[i] < t; i++);
		n = i - 1;
	}
	for(i = 0; i < n; i++){
		for(j = i; j < n; j++){
			temp = array[i]+array[j];
			if(temp > t) break;
			if(temp+max+max < t) break;
			for(k = j; k < n; k++){
				temp = array[i]+array[j]+array[k];
				if(temp > t) break;
				if(temp+max < t) break;
				for(l = k; l < n; l++){
					temp = array[i]+array[j]+array[k]+array[l];
					if(temp == t) return 0;
				}
			}
		}
	}
	return 1;
}

int search1(int *array, int n, int t)
{
	int i, j, k;
	long *a = (long *)calloc(n*n, sizeof(long));
	for(i = 0, k = 0; i < n; i++){
		for(j = i; j < n; j++){
			if(array[i]+array[j] > t) k++;
			a[i+j-k] = (long)(array[i]+array[j]);
		}
	}
	for(i = 0; i < n*n-k; i++){
		for(j = i; j < n*n-k; j++){
			if((long)t == a[i]+a[j]) return 0;
		}
	}
	return 1;
}

int cmp(const void* a, const void* b)
{
	if(*(int *)a < *(int *)b) return -1;
	else if(*( int * )a == *( int * )b) return 0;
	return 1;
}

int prob1(void)
{
	int i, j, n = 1000;
	int *array = (int *)calloc(n*n, sizeof(int));
	clock_t c1, c2, c3;
	srand((unsigned)time(NULL));
	double time;
	for(i = 0; i < 1; i++){
		n = 1+rand()%1000;
		for(j = 0; j < n; j++) array[i] = 1+rand()%N;
		c1 = clock();
		qsort((void *)array, n, sizeof(int), cmp);
		full_search2(array, n, 1+rand()%N);
		c2 = clock();
		time = time + (double)(c2 - c1);
	}
//	printf("%d\n", full_search2(array, n, 1+rand()%N));
//	printf("%d\n", full_search2(array, n, N));
	printf("%f\n",  time / CLOCKS_PER_SEC);
	//	array[0] = 1;
	//	array[1] = 3;
	//	array[2] = 5;
	//	printf("%d\n", full_search2(array, 3, 9));
	return 0;
}

int main(void){
	prob1();
	return 0;
}

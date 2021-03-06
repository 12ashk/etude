#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<math.h>
#define N 100000000

int cmp(const void* a, const void* b){
	if(*(int *)a < *(int *)b) return -1;
	else if(*(int *)a > *(int *)b) return 1;
	return 0;
}

int full_search2(int *array, int n, int t)
{
	int i, j, k, max;
	long temp;
	int *a;
	a = (int *)calloc(n*n, sizeof(int));
	max = array[n-1];
	if(max > t){
		if(max*4 < t) return 1;
		for(i = n-1; array[i] > t; i--);
		n = i+1;
	}
	for(i = 0, k = 0; i < n; i++){
		for(j = i; j < n; j++, k++){
			a[k] = array[i]+array[j];
		}
	}
	qsort((void *)a, n*n, sizeof(int), cmp);
	for(i = 0; i < n*n/2; i++){
		temp = t - a[i];
		if(bsearch(&temp, array+i, n*n-i, sizeof(int), cmp) != NULL) return 0;
	}
	return 1;
}

int prob1(void)
{
	int i, j, n = 1000;
	int *array = (int *)calloc(n, sizeof(int));
	clock_t c1, c2;
	srand((unsigned)time(NULL));
	double time;
	//	n = 3;
	//	array[0] = 1;
	//	array[1] = 3;
	//	array[2] = 5;
	//	c1 = clock();
	//	qsort((void *)array, n, sizeof(int), cmp);
	//	printf("%d\n", full_search2(array, 3, 9));
	//	c2 = clock();
	//	time = (double)(c2 - c1);
	for(i = 0; i < 1; i++){
		n = 1+rand()%1000;
		for(j = 0; j < n; j++) array[i] = 1+rand()%N;
		c1 = clock();
		qsort((void *)array, n, sizeof(int), cmp);
		full_search2(array, n, 1+rand()%N);
		//		printf("%d\n", full_search2(array, n, 1+rand()%N));
		c2 = clock();
		time = time + (double)(c2 - c1);
	}
	printf("%f\n",  time / CLOCKS_PER_SEC);
	return 0;
}

int main(void){
	prob1();
	return 0;
}

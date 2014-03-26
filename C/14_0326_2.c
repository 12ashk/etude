#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<math.h>
#define N 100000000
#define E 0.0000000001

double dist(int *s1, int *s2){
	double x = s1[0]-s2[0];
	double y = s1[1]-s2[1];
	return sqrt(x*x+y*y);
}


//if d1 < d2, return 0, if d1 >= d2 return 1
int comp(double d1, double d2){
	if(d1 + E > d2 && d1 < d2 +E) return 1;
	else if(d1+E < d2) return 0;
	return 1;
}

int myrand(){
	return (rand()%2000)-1000;
}

int rec_search(int **array, int *S, int *V, int x, int n, int *rest, double t, int *f, int c)
{
	int nS[2];
	int i, j;
	double d = dist(S, array[x]);
	if(*f == 1){
		return 0;
	}else if(comp(t+d, dist(array[x], V)) == 0){
		c++;
		if(n == c){
			*f = 1;
			return 0;
		}
		t += d;
		rest[x] = 0;
		nS[0] = array[x][0];
		nS[1] = array[x][1];
		for(i = 0; i < n; i++){
			if(rest[i]){
				int *nrest = (int *)calloc(n, sizeof(int));
				for(j = 0; j < n; j++) nrest[j] = rest[j];
				nrest[i] = 1;
				rec_search(array, nS, V, i, n, nrest, t, f, c);
			}
		}
	}
	return 0;
}


int full_search(int **array, int *S, int *V, int n)
{
	int i, j = 0;
	int *f;
	f = &j;
	int *rest;
	for(i = 0; i < n; i++){
		if(comp(dist(array[i], S), dist(array[i], V)) == 1){
			return 1;
		}
	}
	rest = (int *)calloc(n, sizeof(int));
	for(i = 0; i < n; i++) rest[i] = 1;
	for(i = 0; i < n; i++){
		rec_search(array, S, V, i, n, rest, 0, f, 0);
	}
	if(*f == 1) return 0;

	return 1;
}

int prob2(void){
	srand((unsigned)time(NULL));
	int S[2], V[2];
	int **array;
	int *t;
	int i, n = 20;
	array = (int **)calloc(n, sizeof(int *));
//	n = 3;
//	S[0] = 0;
//	S[1] = 0;
//	V[0] = 10;
//	V[1] = 10;
	for(i = 0; i < n; i++){
		t = (int *)calloc(2, sizeof(int));
		t[0] = myrand(); 
		t[1] = myrand();
		array[i] = t;
	}
//	array[0][0] = 2;
//	array[0][1] = 2;
//	array[1][0] = 4;
//	array[1][1] = 4;
//	array[2][0] = -1;
//	array[2][0] = -3;

	for(i = 0; i < 2; i++){
		S[i] = myrand();
		V[i] = myrand();
	}
	for(i = 0; i < n; i++){
		t = (int *)calloc(2, sizeof(int));
		t[0] = myrand(); 
		t[1] = myrand();
		array[i] = t;
	}
	printf("%d\n", array[10][0]);
	printf("%d\n", full_search(array, S, V, n));

	return 0;
}

int main(void){
	prob2();
	return 0;
}

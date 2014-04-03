#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<float.h>
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
	else if(d1 < d2) return 0;
	return 1;
}

int check(int **array, int *S, int *V, int n,
		int *rest, double t)
{
	int i;
	double d;
	for(i = 0; i < n; i++){
		if(rest[i]){
			d = dist(S, array[i]);
			if(comp(t+d, dist(array[i], V))) return 1;
		}
	}
	return 0;
}

int rec_search(int **array, int *S, int *V, int x,
		int n, int *rest, double t, int *f, int c)
{
	int nS[2];
	double d;
	int i, j;
	rest[x] = 0;
	if(*f == 1)	return 0;
	else if(check(array, S, V, n, rest, t) == 0){
		c++;
		if(n == c) *f = 1;
		else{
			for(i = 0; i < n; i++){
				if(rest[i]){
					nS[0] = array[i][0];
					nS[1] = array[i][1];
					d = dist(nS, S);
					int *nrest = (int *)calloc(n, sizeof(int));
					for(j = 0; j < n; j++) nrest[j] = rest[j];
					rec_search(array, nS, V, i, n, nrest, t+d, f, c);
					free(nrest);
				}
			}
		}
		return 0;
	}
	return 1;
}

int full_search(int **array, int *S, int *V, int n)
{
	int i, j = 0;
	int *f;
	f = &j;
	int *rest;

	rest = (int *)calloc(n, sizeof(int));
	for(i = 0; i < n; i++) rest[i] = 1;
	if(check(array, S, V, n, rest, 0)) return 1;
	for(i = 0; i < n; i++){
		rec_search(array, S, V, i, n, rest, 0, f, 0);
	}
	if(*f == 1) return 0;

	return 1;
}

int main(int argc, char *argv[]){
	int S[2], V[2];
	int **array;
	int i, n = 20;
	FILE *fp;
	array = (int **)calloc(n, sizeof(int *));
	for(i = 0; i < n; i++) array[i] = (int *)calloc(2, sizeof(int *));
	if(argc != 2) return 1;
	if((fp = fopen(argv[1], "r")) == NULL) return 1;
	while(1){
		fscanf(fp, "%d%d%d%d%d", &n, &S[0], &S[1],
				&V[0], &V[1]);
		if(n == 0) return 0;
		for(i = 0; i < n; i++){
			fscanf(fp, "%d%d", &array[i][0], &array[i][1]); 
		}
		if((full_search(array, S, V, n)) == 0) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}

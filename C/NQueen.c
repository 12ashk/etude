#include<stdio.h>
#include<stdlib.h>
#define N 13
int state[N];
int c = 0;

int check(int n, int m);
void seek(int n);

int main(void)
{
	seek(0);
	printf("%d\n", c);
	return 0;
}

int check(int i, int n){
	int j;
	for(j = 0; j < n; j++){
		if(state[j] == i) return 1;
		else if((n-j) == abs(state[j]-i)) return 1;
	}
	return 0;
}

void seek(int n){
	int i;
	if(n == N) c++;
	else{
		for(i = 0; i < N; i++){
			if(check(i, n) == 0){
				state[n] = i;
				seek(n+1);
			}
		}
	}
}

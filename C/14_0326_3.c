#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<math.h>
#define M_m 200
#define M_h 300
#define M_t 500
#define Pr_m 380
#define Pr_h 550
#define Pr_t 850
#define Pa_m 5
#define Pa_h 4
#define Pa_t 3
#define D_m 0.8
#define D_h 0.85
#define D_t 0.88

int calc_P(int i, int j, int k){
	int num_m = i/Pa_m * Pa_m;
	int num_h = j/Pa_h * Pa_h;
	int num_t = k/Pa_t * Pa_t;
	return num_m*Pr_m*D_m+(i-num_m)*Pr_m+num_h*Pr_h*D_h+
		(j-num_h)*Pr_h+num_t*Pr_t*D_t+(k-num_t)*Pr_t;
}

int calc_W(int i, int j, int k, int M){
	int w = i*M_m+j*M_h+k*M_t;
	if(w == M) return 0;
	if(w > M) return 1;
	return -1;
}

int prob3(void){
    srand((unsigned)time(NULL));
    int i, j, k, t;
    int M, price, tp;
	M = 2200;
	price = INT_MAX;
	for(i = 0; i <= M/M_m; i++){
		for(j = 0; j <= M/M_h; j++){
			for(k = 0; k <= M/M_t; k++){
				t = calc_W(i, j, k, M);
				if(t == 0){
					tp = calc_P(i, j, k);
					if(tp < price) price = tp;
				}else if(t == 1) break;
			}
		}
	}
	return price;
}

int main(void){
	printf("%d\n", prob3());
	return 0;
}

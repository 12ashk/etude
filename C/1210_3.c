/* N Queens Puzzle ver.3 UC */
#include<stdio.h>
#define N 13

void findNQueen(struct A, int x);

int count;

struct board{
	int X[N] = {0};
	int R[2*N-1] = {0};
	int L[2*N-1] = {0};
};

int main(void)
{
	int x = 0;
	count = 0;
	struct board A;	
	findNQueen(A, y);
	printf("number of answer is %d\n", count);

	return 0;
}

void findNQueen(struct borad A, int y)
{
	int i, y, flag;
	if(y == N){
		if(N % 2 == 1 && A.Y[N/2] == 1){
			count++;
		}
		else{
			count += 2;
		}
	}
	else{
		for(x = 0; x < N; x++){
			A.X[x] = 1;
			flag = 0;
			if(x == 0){
				if(N % 2 == 0){
					if(x >= N/2){
						break;
					}
				}
				else if(x >= N/2 + 1){
					break;
				}
				A.Y[y]= 1;
				findNQueen(A, y+1);
				A[x][y] = 0;
			}
			else{
				for(i = 0; i < N; i++){
					if(A[i][y] == 1){
						flag = 1;
						break;
					}
				}
				for(i = 0; i < N && flag != 1; i++){
					if(A[x][i] == 1){
						flag = 1;
						break;
					}
				}
				for(i = 1; x+i < N && y+i < N && flag != 1; i++){
					if(A[x+i][y+i] == 1){
						flag = 1;
						break;
					}
				}
				for(i = 1; x+i < N && y-i >= 0 && flag != 1; i++){
					if(A[x+i][y-i] == 1){
						flag = 1;
						break;
					}
				}
				for(i = 1; x-i >= 0 && y+i < N && flag != 1; i++){
					if(A[x-i][y+i] == 1){
						flag = 1;
						break;
					}
				}
				for(i = 1; x-i >= 0 && y-i >= 0 && flag != 1; i++){
					if(A[x-i][y-i] == 1){
						flag = 1;
						break;
					}
				}
				if(flag != 1){
					A[x][y] = 1;
					findNQueen(A, x+1);
					A[x][y] = 0;
				}
			}
		}
	}
}

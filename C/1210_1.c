/* N Queens Puzzle */
#include<stdio.h>
#define N 13

void findNQueen(int A[N][N], int x);

int count;

int main(void)
{
	int A[N][N] = {0};
	int x = 0;
	count = 0;
	findNQueen(A, x);
	printf("number of answer is %d\n", count);
	
	return 0;
}

void findNQueen(int A[N][N], int x)
{
	int i, y, flag;
	if(x == N){
		count++;
	}
	else{
		for(y = 0; y < N; y++){
			flag = 0;
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

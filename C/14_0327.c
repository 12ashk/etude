#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<math.h>

int min(int i, int j){
	if(i < j) return i;
	else return j;
}

int check(int **copy, int i, int j, int c){
	if(copy[i][j] == 0){
		return 1;
	}else if(copy[i][j] > c){
		return 1;
	}else return 0;
}
int solve(int **copy, int i, int j, int *goal, int c)
{
	if(copy[i][j] == 0){
		copy[i][j] = c;
	}else{
		copy[i][j] = min(c, copy[i][j]);
	}
	c++;
	if(goal[0] == i && goal[1] == j) return 0;
	if(check(copy, i+1, j, c)) solve(copy, i+1, j, goal, c);
	if(check(copy, i, j+1, c)) solve(copy, i, j+1, goal, c);
	if(check(copy, i-1, j, c)) solve(copy, i-1, j, goal, c);
	if(check(copy, i, j-1, c)) solve(copy, i, j-1, goal, c);
	return 0;
}

int prob4(void)
{
	int i, j;
	int width, height; 
	int start[2], goal[2];
//	char **lab;
	int **copy;
	width = 9; height = 6;
	char lab[6][9] =
		   {{'.','.','.','#','.','.','.','#','.'},
			{'.','.','#','.','.','#','.','@','#'},
			{'.','.','.','.','#','#','.','.','.'},
			{'.','#','#','#','.','+','#','.','.'},
			{'.','.','.','.','#','.','.','#','.'},
			{'.','#','.','.','.','.','.','#','.'}
		};
//	width = 9; height = 6;
//	char lab[6][9] =
//		   {{'.','.','.','#','.','.','.','#','.'},
//			{'.','.','.','.','.','#','.','@','#'},
//			{'.','.','.','.','#','#','.','.','#'},
//			{'.','.','+','#','.','#','#','.','#'},
//			{'#','.','.','.','.','#','.','.','#'},
//			{'.','#','.','.','.','.','.','#','.'}
//		};
//	width = 11; height = 9;
//	char lab[9][11] = {
//			{'.','#','.','.','.','.','.','.','.', '.', '.'},
//			{'.','#','.','#','#','#','#','#','#', '#', '.'},
//			{'.','#','.','#','.','.','.','.','+', '#', '.'},
//			{'.','#','.','#','.','#','#','#','.', '#', '.'},
//			{'.','#','.','#','.','.','@','#','.', '#', '.'},
//			{'.','#','.','#','#','#','#','#','.', '#', '.'},
//			{'.','#','.','.','.','.','.','.','.', '#', '.'},
//			{'.','#','#','#','#','#','#','#','#', '#', '.'},
//			{'.','.','.','.','.','.','.','.','.', '.', '.'},
//		};
	//	lab = (char **)calloc(height, sizeof(char *));
	//	for(i = 0; i < height; i++) lab[i] = (char *)calloc(width, sizeof(char));
	//	lab = (char **)calloc(height, sizeof(char *));
	//	for(i = 0; i < height; i++) lab[i] = (char *)calloc(width, sizeof(char));
	copy = (int **)calloc(height+2, sizeof(int *));
	for(i = 0; i < height+2; i++) copy[i] = (int *)calloc(width+2, sizeof(int));
	for(i = 0; i < height; i++){
		for(j = 0; j < width; j++){
			if(lab[i][j] == '.') copy[i+1][j+1] = 0;
			else copy[i+1][j+1] = 1;
			if(lab[i][j] == '@'){
				start[0] = i;
				start[1] = j;
				copy[i+1][j+1] = 1;
			}else if(lab[i][j] == '+'){
				goal[0] = i+1;
				goal[1] = j+1;
				copy[i+1][j+1] = 0;
			}
		}
	}
	for(i = 0; i < height+2; i++){
		if(i == 0 || i == height+1){
			for(j = 0; j < width+2; j++) copy[i][j] = 1;
		}else{
			copy[i][0] = 1;
			copy[i][width+1] = 1;
		}
	}
	solve(copy, start[0]+1, start[1]+1, goal, 0);
	return copy[goal[0]][goal[1]];
}

int main(void)
{
	printf("%d\n", prob4());
	return 0;
}

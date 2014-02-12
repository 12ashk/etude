/* iterative deepening depth-first search way */
/* not the shortest distance */
#include<stdio.h>
#define max 100
int boat, num, quit;

struct root{
	int left_M;
	int left_C;
	int boat_side; //if boat is at left side, this is 0, other is 1
	int right_M;
	int right_C;
}path[max];

void find(int depth);
void print_status(int depth);

int main(void)
{
	printf("input number of people that able to get on a boat: ");
	scanf("%d", &boat);
	printf("input number of missionaries and cannibals: ");
	scanf("%d", &num);

	path[0].left_M = num;
	path[0].left_C = num;
	path[0].boat_side = 0;
	path[0].right_M = 0;
	path[0].right_C = 0;
	quit = 0;

	find(0);
	return 0;
}

void find(depth)
{
	int i, j, k, flag = 0;
	if(depth >= max || quit == 1){
	}
	else if(path[depth].right_M == num && path[depth].right_C == num){
		print_status(depth);
		quit = 1;
	}
	else if(path[depth].boat_side == 0){
		for(i = 0; i <= path[depth].left_M && i <= boat; i++){
			for(j = 0; j <= path[depth].left_C && j <= boat; j++){
				if(i == 0 && j == 0){
				}
				else if(i + j <= boat && (j <= i || i == 0)
						&& (path[depth].left_C - j <= path[depth].left_M - i 
							|| path[depth].left_M - i == 0)){
					if(depth != 0){
						for(k = 0; k < depth; k++){
							if(path[k].left_C == path[depth].left_C - j &&
									path[k].left_M == path[depth].left_M - i){
								flag = 1;
								break;
							}
						}
					}
					if(flag == 0){
						path[depth+1].left_C = path[depth].left_C - j;
						path[depth+1].left_M = path[depth].left_M - i;
						path[depth+1].right_C = path[depth].right_C + j;
						path[depth+1].right_M = path[depth].right_M + i;
						path[depth+1].boat_side = 1;
						find(depth+1);
					}
					flag = 0;
				}
			}
		}
	}
	else{
		for(i = 0; i <= path[depth].right_M && i <= boat; i++){
			for(j = 0; j <= path[depth].right_C && j <= boat; j++){
				if(i == 0 && j == 0){
				}
				else if(i + j <= boat && (j <= i || i == 0)
						&& (path[depth].right_C - j <= path[depth].right_M - i 
							|| path[depth].right_M - i == 0)){
					for(k = 0; k < depth; k++){
						if(path[k].right_C == path[depth].right_C - j &&
								path[k].right_M == path[depth].right_M - i){
							flag = 1;
							break;
						}
					}
					if(flag == 0){
						path[depth+1].left_C = path[depth].left_C + j;
						path[depth+1].left_M = path[depth].left_M + i;
						path[depth+1].right_C = path[depth].right_C - j;
						path[depth+1].right_M = path[depth].right_M - i;
						path[depth+1].boat_side = 0;
						find(depth+1);
					}
					flag = 0;
				}
			}
		}
	}
}

	void print_status(depth)
	{
		int i, j;
		for(i = 0; i <= depth; i++){
			printf("%2d: ", i);
			for(j = 0; j < path[i].left_M; j++){
				printf("M");
			}
			for(; j < num; j++){
				printf(" ");
			}
			for(j = 0; j < path[i].left_C; j++){
				printf("C");
			}
			for(; j < num; j++){
				printf(" ");
			}
			if(path[i].boat_side == 0){
				printf("|<_>     |");
			}
			else{
				printf("|     <_>|");
			}
			for(j = 0; j < path[i].right_M; j++){
				printf("M");
			}
			for(; j < num; j++){
				printf(" ");
			}
			for(j = 0; j < path[i].right_C; j++){
				printf("C");
			}
			for(; j < num; j++){
				printf(" ");
			}
			printf("\n");
		}
	}

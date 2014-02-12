/* breadth-first search way Missionaries and Cannibals program*/
/* not complete */
#include<stdio.h>
#include "1217_3.c" // list program

int boat, num, quit;

void find(void); //find ok pattern
void print_status(void);// print list

int main(void)
{
	listinitialize(); //list initialize
	printf("input number of people that able to get on a boat: ");
	scanf("%d", &boat); //number of people that able to ride on
	printf("input number of missionaries and cannibals: ");
	scanf("%d", &num); // number of each people
	struct tnode *t = t_insertlast(t_head);//make tree
	t->left_M = num;
	t->left_C = num;
	t->boat_side = 0;
	t->right_M = 0;
	t->right_C = 0;
	quit = 0;//flag
	push(t_head->next);//push que
	find();
	return 0;
}

void find(void)
{
	int i, j, k, flag = 0;
	if(quit == 1 || q_tail->prev->point == NULL){
	}
	else{
		struct tnode *x;
		x = pop();//pop from que
		if(x->right_M == num && x->right_C == num){
			for(; x != t_head; x = x->prev){//back to head
				x->prev->next = x;
			}
			print_status();
			quit = 1;//flag
		}
		else if(x->boat_side == 0){//boat is at left side
			for(i = 0; i <= x->left_M; i++){//missionary number
				for(j = 0; j <= x->left_C; j++){//cannnibals number
					if(i == 0 && j == 0){//avoid both of them are 0
					}
					else if(i + j <= boat && (j <= i || i == 0)
							&& (x->left_C - j <= x->left_M - i 
								|| x->left_M - i == 0)
							&& (x->right_C + j <= x->right_M + i
								|| x->right_M + i == 0)){
						struct tnode *k = x->prev;
						for(; k != t_head; k = k->prev){
							if(k->left_C == x->left_C - j &&
									k->left_M == x->left_M - i &&
									k->boat_side == 1){
								flag = 1;
								break;
							}
						}
						if(flag == 0){
							struct tnode *t = t_insertlast(x);
							t->left_C = x->left_C - j;
							t->left_M = x->left_M - i;
							t->right_C = x->right_C + j;
							t->right_M = x->right_M + i;
							t->boat_side = 1;
							push(t);//push que
						}
						flag = 0;
					}
				}
			}
		}
		else{//boat is at right side
			for(i = 0; i <= x->right_M; i++){
				for(j = 0; j <= x->right_C; j++){
					if(i == 0 && j == 0){
					}
					else if(i + j <= boat && (j <= i || i == 0)
							&& (x->right_C - j <= x->right_M - i 
								|| x->right_M - i == 0)
							&& (x->left_C + j <= x->left_M + i
								|| x->left_M + i == 0)){
						struct tnode *k = x->prev;
						for(; k != t_head; k = k->prev){
							if(k->right_C == x->right_C - j &&
									k->right_M == x->right_M - i &&
									k->boat_side == 0){
								flag = 1;
								break;
							}
						}
						if(flag == 0){
							struct tnode *t = t_insertlast(x);
							t->left_C = x->left_C + j;
							t->left_M = x->left_M + i;
							t->right_C = x->right_C - j;
							t->right_M = x->right_M - i;
							t->boat_side = 0;
							push(t);
						}
						flag = 0;
					}
				}
			}
		}
		find();
	}
}

void print_status(void)//print all status
{
	int i = 0, j;
	struct tnode *x;
	for(x = t_head->next; x != t_tail; x = x->next){
		printf("%2d: ", i);
		i++;
		for(j = 0; j < x->left_M; j++){
			printf("M");
		}
		for(; j < num; j++){
			printf(" ");
		}
		for(j = 0; j < x->left_C; j++){
			printf("C");
		}
		for(; j < num; j++){
			printf(" ");
		}
		if(x->boat_side == 0){
			printf("|<_>     |");
		}
		else{
			printf("|     <_>|");
		}
		for(j = 0; j < x->right_M; j++){
			printf("M");
		}
		for(; j < num; j++){
			printf(" ");
		}
		for(j = 0; j < x->right_C; j++){
			printf("C");
		}
		for(; j < num; j++){
			printf(" ");
		}
		printf("\n");
	}
}

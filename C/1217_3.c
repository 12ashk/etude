/*linked list*/
#include<stdio.h>
#include<stdlib.h>

struct que//que
{
	struct tnode *point;//to have tree data
	struct que *prev;
	struct que *next;
}*q_head, *q_tail;

struct tnode
{
	int left_M;
	int left_C;
	int boat_side;
	int right_M;
	int right_C;
	struct tnode *next;
	struct tnode *prev;
}*t_head, *t_tail;

void listinitialize(void)//initialize
{
	t_head = (struct tnode*) malloc(sizeof(*t_head));
	t_tail = (struct tnode*) malloc(sizeof(*t_tail));
	t_head->next = t_tail;
	t_tail->next = NULL;
	t_head->prev = NULL;
	t_tail->prev = t_head;
	q_head = (struct que*) malloc(sizeof(*q_head));
	q_tail = (struct que*) malloc(sizeof(*q_tail));
	q_head->next = q_tail;
	q_tail->next = NULL;
	q_head->prev = NULL;
	q_tail->prev = q_head;
}

struct tnode *t_insertlast(struct tnode *x)//insert next
{
	struct tnode *y;
	y = (struct tnode *)malloc(sizeof(*y));
	y->prev = x;
	x->next = y;
	y->next = t_tail;
	t_tail->prev = y;
	return y;
}

void push(struct tnode *p)//push 
{
	struct que *x;
	x = (struct que *)malloc(sizeof(*x));
	x->prev = q_head;
	q_head->next->prev = x;
	x->next = q_head->next;
	q_head->next = x;
	x->point = p;
}

struct tnode *pop(void)
{
	struct tnode *x;
	struct que *t;
	x = q_tail->prev->point;
	t = q_tail->prev->prev;
	t->next = q_tail;
	free(q_tail->prev);
	q_tail->prev = t;
	return x;
}

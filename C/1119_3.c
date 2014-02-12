/* quick sort by linked list */
#include<stdio.h>
#include<stdlib.h>
#include"1112_5.c" //linked list program

void *myqsort(struct node *p, struct node *q);
struct node *partition(struct node *p, struct node *q);

int main(int argc, char *argv[])
{
	int temp;
	FILE *file;
	listinitialize();// function from 1112_5.c
	struct node *t;
	t = head;

	file = fopen(argv[1], "r");
	while(1){// make linked list of file
		if(fscanf(file, "%d", &temp) == EOF){
			break;
		}
		t = insertafter(temp, t);// function from 1112_5.c
	}
	fclose(file);

	myqsort(head->next, t);// t->next == NULL now
	printlist();// function from 1112_5.c

	return 0;
}

void *myqsort(struct node *p, struct node *q)
// p is first of the list, q is end of the list
{
	if(p != q && p != q->next){
		struct node *r;
		r = partition(p, q);
		myqsort(p, r); // first half
		myqsort(r->next, q); // latter half
	}
}

struct node *partition(struct node *p, struct node *q)
// p is first of the list, q is end of the list
{
	int i, temp, pivot;
	struct node *t;
	pivot = p->key;
	t = p;
	do{// define pivot
		t = t->next;
		if(t->key > pivot){
			pivot = t->key;
			break;
		}
	}while(t->key != pivot && t != q);
	if(t == q && p->key == q->key){
		return p;
	}
	while(p != q && p != q->next){
		while(p != q && p != q->next && q->key >= pivot){
			q = q->prev;
		}
		while(p != q && p != q->next && p->key < pivot){
			p = p->next;
		}
		if(p != q){
			temp = p->key;
			p->key = q->key;
			q->key = temp;
			p = p->next;
			q = q->prev;
		}
	}
	if(p == q && p->key < pivot){
		return p;
	}
	else{
		return q;
	}
}

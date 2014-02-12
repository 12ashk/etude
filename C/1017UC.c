/* heap sort UC*/
#include<stdio.h>
#include<stdlib.h>
#define N 2147483647

struct tnode
{
	int key;
	int depth;
	struct tnode *right;
	struct tnode *left;
	struct tnode *parent;
};

struct tnode *root;
root->right = NULL;
root->left = NULL;
root->parent = NULL;
root->key = N;
root->depth = 0;
int maxdepth = 0;

void *delete_min(int key, struct tnode *p);
struct tnode *insert(int key);
struct tnode *exchange(struct tnode *p, struct tnode *q);
struct tnode *findlast(struct tnode *x);

int main(void)
{
	int i, num, key;
	printf("input number of data: ");
	scanf("%d", &num);
	for(i = 0; i < num; i++){
		printf("input data: ");
		scanf("%d", &key);
		insert(key);
	}

	for(i = 0; i < num; i++){
		delete_min();
	}
	printf("\n");

	return 0;
}

void *delete_min(void)
{
	struct tnode *x;
	x = (struct tnode *)malloc(sizeof(*x));
	printf("%d", root->key);
	free(exchange(findlast(root), root));
	x = root;
	while(1){
		if(x->key < x->left->key && x->key < x->right->key){
			break;
		}
		else if(x->key > x->left->key && x->left->key < x->right->key){
			x = exchange(x->left, x);
		}
		else if(x->key > x->right->key && x->right->key < x->left->key){
			x = exchange(x->right, x);
		}
	}
}

struct tnode *insert(int key)
{
	x = (struct tnode *)malloc(sizeof(*x));
	x = finadlast(root);
	x->key = key;
	while(1){
		if(x->key >= x->parent->key){
			break;
		}
		else if(x->key < x->parent->key){
			x = exchange(x->parent, x);
		}
	}
}

struct tnode *exchange(struct tnode *p, struct tnode *q)
{
	int temp;
	temp = p->key;
	p->key = q->key;
	q->key = temp;
	return p;
}

struct tnode *findlast(struct tnode *x)
{
	if(x->key == N){
		return x;
	}
	else if(x->left->key == N){
		struct tnode *last;
		last = (struct tnode *)malloc(sizeof(*last));
		last = x->left;
		last->left = NULL;
		last->right = NULL;
		return last;
	}
	else if(x->right->key == N){
		struct tnode *last;
		last = (struct tnode *)malloc(sizeof(*last));
		last = x->left;
		last->left = N;
		last->ringt = N;
		return last;
	}
	else{
		int temp;
		temp = x->key;
		x = x->parent;
	}
}


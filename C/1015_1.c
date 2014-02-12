#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	int key;
	struct tnode* right;
	struct tnode* left;
};

struct tnode* root = NULL;

struct tnode* addkey(int v, struct tnode *p);
void traverse(struct tnode *p);
int findkey(int v, struct tnode *p);

int main(void)
{
	int i, num, v;
	printf("input number of data: ");
	scanf("%d", &num);
	printf("input data:\n");
	root = (struct tnode *)malloc(sizeof(*root));
	scanf("%d", &v);
	root->key = v;
	root->left = NULL;
	root->right = NULL;

	for(i = 0; i < num-1; i++){
		scanf("%d", &v);
		addkey(v, root);
	}
	traverse(root);
	printf("\n");
	while(1){
		printf("\n1. add data\n"
				"2. print data\n"
				"3.find data\n"
				"input number: ");
		scanf("%d", &num);
		if(num == 1){
			printf("input data: ");
			scanf("%d", &v);
			addkey(v, root);
		}
		else if(num == 2){
			traverse(root);
			printf("\n");
		}
		else if(num == 3){
			printf("input data: ");
			scanf("%d", &v);
			if(findkey(v, root) == 1){
				printf("%d was found\n", v);
			}
			else{
				printf("%d was not found\n", v);
			}
		}
		else{
			break;
		}
	}

	return 0;
}

struct tnode *addkey(int v, struct tnode *p)
{
	if(p == NULL){
		p = (struct tnode *)malloc(sizeof(*p));
		p->key = v;
		p->left = NULL;
		p->right = NULL;
	}
	else if(v < p->key){
		p->left = addkey(v, p->left);
	}
	else{
		p->right = addkey(v, p->right);
	}
	return p;
}

void traverse(struct tnode *p)
{
	if(p != NULL){
		traverse(p->left);
		printf("%d ", p->key);
		traverse(p->right);
	}
}

int findkey(int v, struct tnode *p)
{
	if(p == NULL){
		return 0;
	}
	else if(v == p->key){
		return 1;
	}
	else if(v < p->key){
		return findkey(v, p->left);
	}
	else{
		return findkey(v, p->right);
	}
}

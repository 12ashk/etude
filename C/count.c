/* progressive arrayment */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "convert.c"
#define BUFSIZE 500 /*ファイルから読み込む一行の最大文字数*/
#define GENE_NUMBER 5 /*与えられるプロモータ領域の最大遺伝子数*/
#define GAP -5 // gap score
#define MAX 100

struct promoter
{
	char name[BUFSIZE];
	char seq[BUFSIZE];
	int count;
}pro[GENE_NUMBER];
/* pro: original data */

/*遺伝子のプロモータ領域を保存する構造体*/

int read_promoter(char *filename)
{
	int i=0;
	FILE *fp;
	char buffer[BUFSIZE];

	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("scorefile open error.\n");
		exit(1);
	}

	while(fgets(buffer,sizeof(buffer),fp)!=NULL)
	{
		if(i >= GENE_NUMBER){
			exit(1);
		}
		if(buffer[0]=='>')
		{
			if(buffer[strlen(buffer)-1]=='\n')
				buffer[strlen(buffer)-1]='\0';
			strcpy(pro[i].name,buffer+1); /*遺伝子名を保存*/
		}
		else
		{
			if(buffer[strlen(buffer)-1]=='\n')
				buffer[strlen(buffer)-1]='\0';
			strcpy(pro[i].seq,buffer); /*遺伝子のプロモータ領域の配列を保存*/
			i++;
		}
	}
	return i;
}

int main(int argc,char *argv[])
{
	int i, j, k, l, f, x, y, count, gene_num, seq_len;

	gene_num=read_promoter(argv[1]);
	seq_len = strlen(pro[0].seq);
	for(i = 0; i < gene_num; i++){
		pro[i].count = 0;
		for(j = 0; j < seq_len; j++){
			pro[i].count += convert(pro[i].seq[j]);
		}
	}

	for(i = 0; i < gene_num; i++){
		printf("%s> %d\n", pro[i].name, pro[i].count);
	}

	return 0;
}

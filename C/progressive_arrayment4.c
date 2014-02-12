/* progressive arrayment */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "score_matrix.c"
#define BUFSIZE 500 /*ファイルから読み込む一行の最大文字数*/
#define GENE_NUMBER 5 /*与えられるプロモータ領域の最大遺伝子数*/
#define GAP -5 // gap score
#define MAX 100

int dp[BUFSIZE][BUFSIZE] = {0}; //score table
int trace[BUFSIZE][BUFSIZE] = {0}; // the way of coming from

struct combination/* to remeber score to make genelogical tree */
{
	int x;
	int y;
	char x_name[BUFSIZE];
	char y_name[BUFSIZE];
	int score;
}comb[GENE_NUMBER*GENE_NUMBER];

struct promoter
{
	char name[BUFSIZE];
	char seq[BUFSIZE];
}pro[GENE_NUMBER], result[GENE_NUMBER], cluster[GENE_NUMBER/2];
/* pro: original data */

/*遺伝子のプロモータ領域を保存する構造体*/

/*return macth/mismatch score*/
int get_score(char a, char b)
{
	return score[conv(a)][conv(b)];
}

/*get max match score */
int match_score(int i, int j, int x, int y, int f)
{
	int case1, case2, case3;
	int result, come;
	int k;
	if(f == 0){/* compare to make genelogical tree */
		case1 = dp[i-1][j-1] + get_score(pro[x].seq[i], pro[y].seq[j]);
		case2 =	dp[i-1][j] + GAP;
		case3 =	dp[i][j-1] + GAP;
	}
	else{
		for(k = 0; cluster[k].name[0] != '\0'; k++){
				case1 = dp[i-1][j-1] + get_score(cluster[k].seq[i], pro[x].seq[j]);
				case2 =	dp[i-1][j] + GAP;
				case3 =	dp[i][j-1] + GAP;
		}
	}
	result = case1;
	come = 1;
	if(case2 > result){
		result = case2;
		come = 2;
	}
	else if(case3 > result){
		result = case3;
		come = 3;
	}
	trace[i][j] = come;
	/*come form*/
	return result;
}

/*make dp table */
void make_map(int seq_len, int x, int y, int f) 
{
	int i, j;
	for(i = 0; i < seq_len; i++){//initialize dp table
		dp[i][0] = i * GAP;
		dp[0][i] = i * GAP;
	}
	for(i = 1; i < seq_len; i++){
		for(j = 1; j < seq_len; j++){
			dp[i][j] = match_score(i, j, x, y, f);
		}
	}
}

/* traceback to make result seq */

int traceback(int i, int j, int y)
{
	int index;
	if(i == 0 && j == 0){
		return 0;
	}
	else if(trace[i][j] == 1){
		index = traceback(i-1, j-1, y);
		if(y == 1){/*make result[0] */
			result[0].seq[index] = pro[0].seq[i-1];
		}
		result[y].seq[index] = pro[y].seq[j-1];
	}
	else if(trace[i][j] == 2){
		index = traceback(i-1, j-1, y);
		if(y == 1){
			result[0].seq[index] = pro[0].seq[i-1];
		}
		result[y].seq[index] = '-';
	}
	else if(trace[i][j] == 3){
		index = traceback(i-1, j-1, y);
		if(y == 1){
			result[0].seq[index] = '-';
		}
		result[y].seq[index] = pro[y].seq[j-1];
	}
	return index+1;
}

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

void print_result(int gene_num)
{
	int i;
	for(i = 0; i < gene_num; i++){
		printf(">%s\n%s\n", result[i].name, result[i].seq);
	}
}

void make_tree(int count)
{
	int i;
	struct combination max;

	max.score = comb[0].score;
	max.x = comb[0].x;
	max.y = comb[0].x;

	for(i = 1; i < count; i++){/*sort by score */
		if(max.score < comb[i].score){
			max.score = comb[i].score;
			max.x = comb[i].x;
			max.y = comb[i].x;
		}
	}
	for(i = 0; cluster[i].name[0] != '\0'; i++){
	}
	strcpy(cluster[i].name, pro[max.x].name);
	strcpy(cluster[i+1].name, pro[max.y].name);
	strcpy(cluster[i].seq, pro[max.x].seq);
	strcpy(cluster[i].seq, pro[max.y].seq);
}

int main(int argc,char *argv[])
{
	int i, j, k, l, f, x, y, count, gene_num, seq_len;
	//１番目の引数で指定した転写因子の複数の結合部位配列を読み込む
	gene_num=read_promoter(argv[1]);
	printf("%d", gene_num);
	for(i=0;i<gene_num;i++){
		printf(">%s\n%s\n", pro[i].name, pro[i].seq);
	}
	printf("------------------\n");
	seq_len = strlen(pro[0].seq);
	count = 0;
	for(k = 0; k < gene_num-1; k++){
		for(i = 0; i < gene_num-1; i++){/*make genelogical tree */
			for(j = i+1; j < gene_num; j++){
				f = 0;
				for(l = 0; cluster[l].name[0] != '\0'; l++){
					if(strcmp(cluster[l].name, pro[i].name) || strcmp(cluster[l].name, pro[j].name)){
						f = 1;
						break;
					}
				}
				if(f == 0){
					if(cluster[0].name[0] == '\0'){
						make_map(seq_len, i, j, 0);
					}
					else{
						make_map(seq_len, i, j, 1);
					}
					strcpy(comb[count].x_name, pro[i].name);
					strcpy(comb[count].y_name, pro[j].name);
					comb[count].x = i;
					comb[count].y = j;
					comb[count].score = dp[seq_len-1][seq_len-1];
					count++;
				}
			}
		}
		make_tree(count);
	}
	for(i = 1; i < gene_num; i++){
		make_map(seq_len, i, j, 1);
		if(i == 1){
			strcpy(result[0].name, pro[i].name);
		}
		strcpy(result[i].name, pro[i].name);
		traceback(seq_len-1, seq_len-1, i);
	}
	print_result(gene_num);
	return 0;
}

/* progressive arrayment */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define BUFSIZE 500 /*ファイルから読み込む一行の最大文字数*/
#define GENE_NUMBER 5 /*与えられるプロモータ領域の最大遺伝子数*/
#define GAP -5 // gap score

int dp[BUFSIZE][BUFSIZE] = {0}; //score table
int trace[BUFSIZE][BUFSIZE] = {0}; // the way of coming from

struct combination/* to remeber score to make genelogical tree */
{
	int x;
	char name[BUFSIZE];
	int score;
}comb[GENE_NUMBER*GENE_NUMBER];

struct promoter
{
	char name[BUFSIZE];
	char seq[BUFSIZE];
}pro[GENE_NUMBER+GENE_NUMBER], result[GENE_NUMBER];
/* pro: original data */

/*遺伝子のプロモータ領域を保存する構造体*/

/*return macth/mismatch score*/
int get_score(char a, char b)
{
	if(a == b){
		return 1; // match
	}
	else if(a != b){
		return -1; //not match
	}
}

/*get max match score */
int match_score(int i, int j, int f, int x)
{
	int case1, case2, case3;
	int result, come;
	int k;
	if(f == 0){/* compare to make genelogical tree */
		case1 = dp[i-1][j-1] + get_score(pro[0].seq[i], pro[x].seq[j]);
		case2 =	dp[i-1][j] + GAP;
		case3 =	dp[i][j-1] + GAP;
	}
	else{/* compare to make result and make average score of cluster*/
		for(k = 0; k < x; k++){
			case1 = dp[i-1][j-1] + get_score(pro[k].seq[i], pro[x].seq[j]);
			case2 =	dp[i-1][j] + GAP;
			case3 =	dp[i][j-1] + GAP;
		}
		case1 /= k;
		case2 /= k;
		case3 /= k;
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
void make_map(int seq_len, int f, int x) 
{
	int i, j;
	for(i = 0; i < seq_len; i++){//initialize dp table
		dp[i][0] = i * GAP;
		dp[0][i] = i * GAP;
	}
	for(i = 1; i < seq_len; i++){
		for(j = 1; j < seq_len; j++){
			dp[i][j] = match_score(i, j, f, x);
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
			result[0].seq[index] = pro[0].seq[i];
		}
		result[y].seq[index] = pro[y].seq[j];
	}
	else if(trace[i][j] == 2){
		index = traceback(i-1, j-1, y);
		if(y == 1){
			result[0].seq[index] = pro[0].seq[i];
		}
		result[y].seq[index] = '-';
	}
	else if(trace[i][j] == 3){
		index = traceback(i-1, j-1, y);
		if(y == 1){
			result[0].seq[index] = '-';
		}
		result[y].seq[index] = pro[y].seq[j];
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
			printf("too many sequences.\nMax number is %d\n.", GENE_NUMBER);
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
	int i, j;
	struct combination temp;
	struct promoter tmp;

	for(i = count; i > 0; i--){/*sort by score */
		/* I thought bigger score means closer */ 
		for(j = 1; j < i; j++){
			if(comb[j-1].score < comb[j].score){
				temp = comb[j-1];
				comb[j-1] = comb[j];
				comb[j] = temp;
			}
		}
	}
	for(i = 0; i < count; i++){
		if(strcmp(comb[i].name, pro[i+1].name)){
			tmp = pro[i+1];
			pro[i+1] = pro[comb[i].x];
			pro[comb[i].x] = tmp;
		}
	}
}

int main(int argc,char *argv[])
{
	int i, j, x, y, count, gene_num, seq_len;
	//１番目の引数で指定した転写因子の複数の結合部位配列を読み込む
	gene_num=read_promoter(argv[1]);
	for(i=0;i<gene_num;i++){
		printf(">%s\n%s\n", pro[i].name, pro[i].seq);
	}
	printf("------------------\n");
	seq_len = strlen(pro[0].seq);
	count = 0;
	for(i = 1; i < gene_num; i++){/*make genelogical tree */
		/* Compare 0 with others,
		 * it is not good way, but it is easy to implement*/
		make_map(seq_len, 0, i);
		comb[count].x = i;
		strcpy(comb[count].name, pro[i].name);
		comb[count].score = dp[seq_len-1][seq_len-1];
		count++;
	}
	make_tree(count);
	for(i = 1; i < gene_num; i++){
		make_map(seq_len, 1, i);
		if(i == 1){
			strcpy(result[0].name, pro[0].name);
		}
		strcpy(result[i].name, pro[i].name);
		traceback(seq_len-1, seq_len-1, i);
	}
	print_result(gene_num);
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define BUFSIZE 400 /*ファイルから読み込む一行の最大文字数*/
#define GENE_NUMBER 3 /*与えられるプロモータ領域の最大遺伝子数*/
#define GAP -5 // gap score

int dp[BUFSIZE][BUFSIZE][BUFSIZE] = {0}; //score table
int trace[BUFSIZE][BUFSIZE][BUFSIZE] = {0}; // the way of coming from

struct array
{
	int x, y, z; //coordinates
	int value;
}max;

struct promoter
{
	char name[BUFSIZE];
	char seq[BUFSIZE];
	char result[BUFSIZE]; //seq of consensus array
}pro[GENE_NUMBER];

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
int match_score(int i, int j, int k)
{
	int case1, case2, case3, case4, case5, case6, case7;
	int result, come;

	case1 = dp[i-1][j-1][k-1] + get_score(pro[0].seq[i], pro[1].seq[j]) 
		+ get_score(pro[0].seq[i], pro[2].seq[k]) + get_score(pro[1].seq[j], pro[2].seq[k]);
	case2 = dp[i-1][j-1][k] + get_score(pro[0].seq[i], pro[1].seq[j]) + 2*GAP;
	case3 = dp[i-1][j][k-1] + get_score(pro[0].seq[i], pro[2].seq[k]) + 2*GAP;
	case4 =	dp[i][j-1][k-1] + get_score(pro[1].seq[j], pro[2].seq[k]) + 2*GAP;
	case5 =	dp[i-1][j][k] + 2*GAP;
	case6 =	dp[i][j-1][k] + 2*GAP;
	case7 =	dp[i][j][k-1] + 2*GAP;
	result = case1;
	come = 1;
	if(case2 > result){
		result = case2;
		come = 2;
	}
	if(case3 > result){
		result = case3;
		come = 3;
	}
	if(case4 > result){
		result = case4;
		come = 4;
	}
	if(case5 > result){
		result = case5;
		come = 5;
	}
	if(case6 > result){
		result = case6;
		come = 6;
	}
	if(case7 > result){
		result = case7;
		come = 7;
	}
	if(result <= 0){
		result = 0;
		come = 0;
	}
	trace[i][j][k] = come;
	/*come form*/
	return result;
}

/*make dp table */
void make_map(int seq_len)
{
	int i, j, k;
	int x, y, z;
	max.value = 0;//initialize
	for(i = 1; i < seq_len; i++){
		for(j = 1; j < seq_len; j++){
			for(k = 1; k < seq_len; k++){
				dp[i][j][k] = match_score(i, j, k);
				if(dp[i][j][k] > max.value){
					max.value = dp[i][j][k];
					max.x = i;
					max.y = j;
					max.z = k;
				}
			}
		}
	}
}

/*traceback to make result seq */
int traceback(int i, int j, int k)
{
	int index;
	if(trace[i][j][k] == 0){
		return 0;
	}
	else if(trace[i][j][k] == 1){
		index = traceback(i-1, j-1, k-1);
		pro[0].result[index] = pro[0].seq[i];
		pro[1].result[index] = pro[1].seq[j];
		pro[2].result[index] = pro[2].seq[k];
	}
	else if(trace[i][j][k] == 2){
		index = traceback(i-1, j-1, k);
		pro[0].result[index] = pro[0].seq[i];
		pro[1].result[index] = pro[1].seq[j];
		pro[2].result[index] = '-';
	}
	else if(trace[i][j][k] == 3){
		index = traceback(i-1, j, k-1);
		pro[0].result[index] = pro[0].seq[i];
		pro[1].result[index] = '-';
		pro[2].result[index] = pro[2].seq[k];
	}
	else if(trace[i][j][k] == 4){
		index = traceback(i, j-1, k-1);
		pro[0].result[index] = '-';
		pro[1].result[index] = pro[1].seq[j];
		pro[2].result[index] = pro[2].seq[k];
	}
	else if(trace[i][j][k] == 5){
		index = traceback(i-1, j, k);
		pro[0].result[index] = pro[0].seq[i];
		pro[1].result[index] = '-';
		pro[2].result[index] = '-';
	}
	else if(trace[i][j][k] == 6){
		index = traceback(i, j-1, k);
		pro[0].result[index] = '-';
		pro[1].result[index] = pro[1].seq[j];
		pro[2].result[index] = '-';
	}
	else if(trace[i][j][k] == 7){
		index = traceback(i, j, k-1);
		pro[0].result[index] = '-';
		pro[1].result[index] = '-';
		pro[2].result[index] = pro[2].seq[k];
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
			printf("too many genes.\nmax gene number is 3.\n");
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
		printf(">%s\n%s\n", pro[i].name, pro[i].result);
	}
}

int main(int argc,char *argv[])
{
	int i,gene_num, seq_len;
	//１番目の引数で指定した転写因子の複数の結合部位配列を読み込む
	gene_num=read_promoter(argv[1]);
	for(i=0;i<gene_num;i++){
		printf(">%s\n%s\n", pro[i].name, pro[i].seq);
	}
	printf("------------------\n");
	seq_len = strlen(pro[0].seq);
	make_map(seq_len);
	traceback(max.x, max.y, max.z);
	print_result(gene_num);
	return 0;
}

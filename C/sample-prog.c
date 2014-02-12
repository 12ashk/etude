#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define BUFSIZE 1024 /*ファイルから読み込む一行の最大文字数*/
#define SEQ_NUMBER 30 /*一つの転写因子に対して与えられる結合部位配列の最大数*/
#define GENE_NUMBER 8 /*与えられるプロモータ領域の最大遺伝子数*/

char motif[SEQ_NUMBER][BUFSIZE]; /*転写因子の結合部位配列を保存する配列*/
int freq_table[4][SEQ_NUMBER] = {0};
int background[4] = {7519429, 4637676, 4637676, 7519429};
double odds_table[4][SEQ_NUMBER] = {0};

struct promoter
{
	char name[BUFSIZE];
	char seq[BUFSIZE];
	float score[BUFSIZE];
	float n_score[BUFSIZE];
	float average;
	float variance;
	float std_div;
}pro[GENE_NUMBER];

/*遺伝子のプロモータ領域を保存する構造体*/

int read_multi_seq(char *filename)
{
	int i=0;
	int q;
	FILE *fp;
	char buffer[BUFSIZE];
	int buf_len;

	if((fp=fopen(filename,"r"))==NULL) /* ファイルを開く*/
	{
		printf("scorefile open error.\n"); 
		exit(1); /*ファイルを開くことに失敗した場合終了する*/
	}
	while(fgets(buffer,sizeof(buffer),fp)!=NULL) /*ファイルから一行ずつ読み込む*/
	{
		if(buffer[strlen(buffer)-1]=='\n')
			buffer[strlen(buffer)-1]='\0'; /*改行を切り落とす*/
		strcpy(motif[i],buffer); /*結合部位配列を保存*/
		i++;
	}
	return i; /*結合部位配列の数を返す*/
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

int make_freq_table(int seq_num)
{
	int i, j;
	int gene_num = strlen(motif[0]);

	for(j = 0; j < gene_num; j++){
		for(i = 0; i < seq_num; i++){
			if(motif[i][j] == 'A'){
				freq_table[0][j]++;
			}
			else if(motif[i][j] == 'T'){
				freq_table[1][j]++;
			}
			else if(motif[i][j] == 'G'){
				freq_table[2][j]++;
			}
			else if(motif[i][j] == 'C'){
				freq_table[3][j]++;
			}
		}
	}
}

int make_odds_table(int seq_num)
{
	int i, j;
	int gene_num = strlen(motif[0]);
	double temp, allnum, allback = 0;
	allnum = seq_num + 4;
	for(i = 0; i < 4; i++){
		allback += background[i];
	}

	for(j = 0; j < gene_num; j++){
		for(i = 0; i < 4; i++){
			temp = freq_table[i][j]+1;
			odds_table[i][j] = log((temp/allnum) / (background[i]/allback));
		}
	}
}

int convert(char base)
{
	if(base == 'A'){
		return 0;
	}
	else if(base == 'T'){
		return 1;
	}
	else if(base == 'G'){
		return 2;
	}
	else{
		return 3;
	}
}

double hit(char gene[])
{
	double result = 0;
	int i;
	for(i = 0; i < strlen(motif[0]); i++){
		result += odds_table[convert(gene[i])][i];
	}
	return result;
}

void scan_bindingsite(int gene_num)
{
	int i, j, k, seq_num = strlen(motif[0]);
	char temp[seq_num];
	for(i = 0; i < gene_num; i++){
		for(j = 0; j <= strlen(pro[i].seq)-seq_num; j++){
			for(k = 0; k < seq_num; k++){
				temp[k] = pro[i].seq[j+k];
			}
			pro[i].score[j] = hit(temp);
		}
	}
}

void calc_std_div(int gene_num, int seq_num)
{
	int i, j;
	for(i = 0; i < gene_num; i++){
		pro[i].average = 0;
		pro[i].variance = 0;
		for(j = 0; j <= strlen(pro[i].seq)-seq_num; j++){
			pro[i].average += pro[i].score[j];
			pro[i].variance += (pro[i].score[j]*pro[i].score[j]);
		}
		pro[i].average /= (j-1);
		pro[i].variance /= (j-1);
		pro[i].variance -= pro[i].average*pro[i].average;
		pro[i].std_div = sqrt(pro[i].variance);
	}
}

void convert_to_normal(int gene_num, int seq_num){
	float threshold;
	int i, j, k;
	printf("input threshold of z value: ");
	scanf("%f", &threshold);
	for(i = 0; i < gene_num; i++){
		printf("%s>\n", pro[i].name);
		for(j = 0; j <= strlen(pro[i].seq)-seq_num; j++){
			pro[i].n_score[j] = (pro[i].score[j] - pro[i].average) / pro[i].std_div;
			if(pro[i].n_score[j] >= threshold){
				printf("%.2f: ", pro[i].score[j]);
				for(k = 0; k < strlen(motif[0]); k++){
					printf("%c", pro[i].seq[k]);
				}
				printf("\n");
			}
		}
		printf("\n");
	}
}

int main(int argc,char *argv[])
{
	int i,seq_num,gene_num;
	seq_num=read_multi_seq(argv[1]); /*１番目の引数で指定した転写因子の複数の結合部位配列を読み込む*/
//	printf("----in motif[]----\n");
//	for(i=0;i<seq_num;i++){
//		printf("%s\n",motif[i]); /*読み込んだ転写因子の結合部位配列を表示*/
//	}
//	printf("------------------\n");
//
//	printf("-----in pro[]-----\n");
	gene_num=read_promoter(argv[2]); /*２番目を複数で指定した遺伝子のプロモータ領域を読み込む*/
//	for(i=0;i<gene_num;i++){
//		printf(">%s\n%s\n",pro[i].name,pro[i].seq); /*読み込んだプロモータ領域を表示*/
//	}
//	printf("------------------\n");
	make_freq_table(seq_num);
	make_odds_table(seq_num);
	printf("%s\n", argv[1]);
	scan_bindingsite(gene_num);
	calc_std_div(gene_num, seq_num);
	convert_to_normal(gene_num, seq_num);
	return 0;
}

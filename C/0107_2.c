/*
 * This program is incomplete. To make it perfect, you have to write
 * three functions:
 *    'scoref()', 'align()' and 'traceback()'
 * Have a fun!
 */
#include <stdio.h>
#include "score-matrix2.c"
#define MAX_SEQ 1024		/* maximum length of sequences */
#define M  0			/* match state */
#define IX 1			/* insert state */
#define IY 2			/* delete state */

char x[MAX_SEQ];		/* seq1 */
char y[MAX_SEQ];		/* seq2 */
float D[MAX_SEQ][MAX_SEQ]; /* DP table */
int T[MAX_SEQ][MAX_SEQ]; /* trace table */
char res_x[MAX_SEQ*2];		/* alignment result of x */
char res_y[MAX_SEQ*2];		/* alignment result of y */
float d = -8;			/* gap score */

/*
 * return the substitution score between x and y
 */

float scoref(char x, char y)
{
	int i, j;
	i = conv(x);
	j = conv(y);
	return (float)score[i][j];
}

/*
 * fill D and T according to the algorithm "align",
 * and return the maximum socre of alignment.
 */
float align(int len_x, int len_y)
{
	int i, j, case1, case2, case3;
	/* case1 is match, case2 is insert, case3 is delete */
	D[0][0] = 0;
	for(i = 1; i < len_x; i++){
		D[i][0] = D[i-1][0] + d;
	}
	for(j = 1; j < len_y; j++){
		D[0][j] = D[0][j-1] + d;
	}
	for(i = 1; i < len_x; i++){
		for(j = 1; j < len_y; j++){
			case1 = D[i-1][j-1] + scoref(x[i], y[j]);
			case2 = D[i-1][j] + d;
			case3 = D[i][j-1] + d;
			if(case1 >= case2 && case1 >= case3){
				D[i][j] = case1;
				T[i][j] = M;
			}
			else if(case2 > case1 && case2 >= case3){
				D[i][j] = case2;
				T[i][j] = IX;
			}
			else{
				D[i][j] = case3;
				T[i][j] = IY;
			}
		}
	}
	return D[len_x-1][len_y-1];
}

/*
 * trace back the result of align() to make pairwise alignment,
 * and return the length of alignment.
 */
int traceback(int i, int j)
{
	if(i <= 0 && j <= 0){
		return 0;
	}
	else{
		int t;
		if(T[i][j] == M){
			t = traceback(i-1, j-1);
			res_x[t] = x[i];
			res_y[t] = y[j];
			return t + 1;
		}
		else if(T[i][j] == IX){
			t = traceback(i-1, j);
			res_x[t] = x[i];
			res_y[t] = '-';
			return t + 1;
		}
		else{
			t = traceback(i, j-1);
			res_x[t] = '-';
			res_y[t] = y[j];
			return t + 1;
		}
	}
}

/*
 * read a seqence from the file whose name is "filename" 
 * to the buffer "seq", and return the length of the sequence.
 * 
 */
int read_seq(char *filename, char *seq)
{
	FILE *fp;
	char ch;
	int i;

	seq[0] = ' ';

	fp = fopen(filename, "r");

	if(fp == NULL){
		return 0;
	}

	ch = fgetc(fp);
	for(i = 1; ch != '\n' && ch != EOF; i++){
		seq[i] = ch;
		ch = fgetc(fp);
	}
	fclose(fp);
	return i;
}

/*
 * print the result of alignment to stdout.
 */
void print_result(int maxl)
{
	int i;
	for(i = 0; i < maxl; i++){
		putc(res_x[i], stdout);
	}
	putc('\n', stdout);
	for(i = 0; i < maxl; i++){
		putc(res_y[i], stdout);
	}
	putc('\n', stdout);
}

/*
 * print the contents of D and T for debugging.
 */
void print_matrix(int len_x, int len_y)
{
	int i, j;
	static char *arrow = "MXY";

	printf("  ");
	for(i = 0; i < len_x; i++){
		printf("  %c ", x[i]);
	}
	printf("\n");

	for(j = 0; j < len_y; j++){
		printf("%c ", y[j]);
		for(i = 0; i < len_x; i++) {
			printf("%2d%c ", (int)D[i][j], arrow[T[i][j]]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	int len_x, len_y, maxl;
	float score;
	len_x = read_seq(argv[1], x);
	len_y = read_seq(argv[2], y);
	score = align(len_x, len_y);
	//print_matrix(len_x, len_y); 
	maxl = traceback(len_x-1, len_y-1);
	printf("score %f\n", score);
	print_result(maxl);

	return 0;
}

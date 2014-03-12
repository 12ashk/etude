#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i, j;
	int a[10][10];
	int *b;
	// bにaのポインタを渡してそれを元に
	// aのポインタにそこからの移動度を足した値を取得
	// エラー出る
	// &a[0][0]渡すとエラーでないから
	// ソッチのほうが無難かも
	b = a;
	for(i = 0; i < 10; i++) a[7][i] = i;
	for(i = 0; i < 10; i++) printf("%d ", *(b+7*10+i));
	printf("\n");
	int **c;
	// cにa[i]のポインタを渡してそれをもとに
	// a[i]+jのポインタの値を取得
	// cはポインタの配列
	c = (int **)malloc(10*sizeof(int *));
	for(i = 0; i < 10; i++) c[i] = a[i];
	for(i = 0; i < 10; i++) printf("%d ", *(a[7]+i));
	printf("\n");
	//cにa[i]のポインタを渡してそれをもちに
	//a[i][j]の値を取得
	//cを配列likeにつかえる
	c = (int **)malloc(10*10*sizeof(int *));
	for(i = 0; i < 10; i++) c[i] = a[i];
	for(i = 0; i < 10; i++) printf("%d ", c[7][i]);
	printf("\n");
	return 0;
}

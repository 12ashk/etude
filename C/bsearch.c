#include<stdio.h>
#include<stdlib.h>

// 比較する関数
// qsortとbsearchの比較関数の引数の型
// の指定がconst void*なのでとりあえず
// 型をそのように指定している
int cmp(const void* a, const void* b){
	//const void*だと比較できないので
	//int *型に変換している(intのポインタ型)
	//それを*をつけてポインタの中身で比較している
	//intじゃなくしたかったらintを適当にfloatとか
	//doubleとかにすれば使えます
	if(*(int *)a < *(int *)b) return -1;
	else if(*(int *)a > *(int *)b) return 1;
	return 0;
}

int main(void){
	int size = 100;
	int num = 23;
	int *a;
	int array[100];
	//とりあえず0から99までの配列を作成
	for(int i = 0; i < 100; array[i] = i, i++);

	// 第1引数は配列, 第2引数は配列サイズ、
	// 第3引数は配列の中身の大きさ、最後は比較する関数
	// 第1引数の要求する型がvoid *なので
	// 型変換変換している
	qsort((void *)array, size, sizeof(int), cmp);
	// 第1引数は探したい変数のポインタ
	// 第2引数は配列, 第3引数は配列サイズ、
	// 第4引数は配列の中身の大きさ、最後は比較する関数
	// 返り値は、見つかったらその変数のポインタ、
	// 見つからなかったらNULLが返ってきます
	a = bsearch(&num, array, size, sizeof(int), cmp);
	printf("%d\n", *a);
	return 0;
}

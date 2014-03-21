#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define N 256

typedef struct _BinSTreeNode
{
	char *word;
	struct _BinSTreeNode *left;
	struct _BinSTreeNode *right;
	struct _BinSTreeNode *pare;
} BinSTreeNode;

int my_strlen(const char *str)
{
	int i;
	for(i = 0; str[i] != '\0'; i++);
	return i;
}

int min(int i, int j){
	if(i < j) return i;
	return j;
}

/* 基本的に小さい文字を返す */
/* 同じ時だけ0 */
const char *my_strcmp(const char *str1, const char *str2)
{
	int i = 0;
	int num, len1, len2;
	len1 = my_strlen(str1);
	len2 = my_strlen(str2);
	num = min(len1, len2);	
	for(i = 0; i < num; i++){
		if(str1[i] < str2[i]) return str1;
		if(str2[i] < str1[i]) return str2;
	}
	if(len1 < len2) return str1;
	else if(len1 > len2) return str2;
	return 0;
}

char *my_strncpy(char *str1, const char *str2, int num)
{
	int i;
	char *str = (char *)malloc(sizeof(str1));
	int n = min(num, strlen(str2));
	for(i =	0; i < n; i++){
		str[i] = str2[i];
	}
	while(str1[i] != '\0'){
		str[i] = str1[i];
		i++;
	}
	str1 = str;
	return str;
}

char *my_chomp(char *str)
{
	int i = strlen(str);
	if(str[i-1] != '\n') return str;
	char *s = (char *)malloc(sizeof(char *)*i);
	s = my_strncpy(s, str, i-1);
	s[i-1] = '\0';
	return s;
}

char *my_subst(char *str1, char *str2, char *str3)
{
	int i, j, k, h;
	int len1, len2, len3;
	len1 = strlen(str1);
	len2 = strlen(str2);
	len3 = strlen(str3);
	char *str = (char *)malloc(sizeof(char *)*100);
	for(i = 0; i < len1+1; i++) str[i] = str1[i];
	for(i = 0, h = 0; str[i] != '\0'; i++, h++){
			for(j = 0; j < len2 && str[i+j] == str2[j]; j++);
			if(j == len2){
				for(j = 0; j < len3; j++) str[i+j] = str3[j];
				for(k = h+len2; k <= len1; j++, k++) str[i+j] = str1[k];
				i = i+len3-1;
				h = h+len2-1;
			}
	}
	char *s = (char *)malloc(sizeof(char *)*strlen(str));
	for(i = 0; i <= strlen(str); i++) s[i] = str[i];
	return str;
}

int add(BinSTreeNode node, char *word){
	printf("%s\n", word);
	return 0;
}

char *cutstr(char *str, int i, int j)
{
	char *s = (char *)malloc(sizeof(char *)*(j-i+1));
	int k;
	for(k = 0; k + i <= j; k++) s[k] = str[k+i];
	return s;
}

int add_from_line(char *str, BinSTreeNode root){
	int i, j;
	for(i = 0, j = 0; str[i-1] != '\n'; i++){
		if(j != i && (str[i] == ' ' || str[i] == '\n')){
			add(root, cutstr(str, j, i-1));
			j = i+1;
		}
		if(str[i] == ' ' && i == j) j++;
	}
	return 0;
}

int add_from_file(FILE *fp, BinSTreeNode root)
{
	char *str = (char *)malloc(sizeof(char *)*100);
	while(fgets(str, N, fp) != NULL){
		add_from_line(str, root);
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int i, j;
	char *str;
	FILE *fp;
	BinSTreeNode rootNode;
	for(i = 1; i < argc; i++){
		if(argv[i][0] != '-' && argv[i][0] != '/' && !(isnumber(argv[i][0]))){
			fp = fopen(argv[i], "r");
			if(fp == NULL) exit(1);
			add_from_file(fp, rootNode);
			fclose(fp);
		}
	}
	//	if(rootNode->word == NULL){
	//	while(1){
	//		fgets(str, N, stdin);
	//		add_from_line(str);
	//	}
	//	if(argc == 1) printTree(0);
	for(i = 1; i < argc; i++){
		if(argv[i][0] == '-' || argv[i][0] == '/' || isnumber(argv[i][0])){
			if(strcmp(argv[i], "-p") == 0 && i+1 < argc){
				if(isdigit(argv[i+1][0])){
					printf("printTree, %d\n", atoi((const char*)argv[i+1]));
					i++;
				}else{
					printf("printTree, 0\n");
				}
			}
			if(strcmp(argv[i], "-r") == 0){
				if(i+1 == argc || argv[i+1][0] != '/') exit(1);
				for(i++, j = 1; j < strlen(argv[i]); j++){
						if(argv[i][j] == '/'){
							str = cutstr(argv[i], 1, j-1);
							if(argv[i][j+1] == '0') printf("remove %s all\n", str);
							else printf("remove %s onece\n", str);
							break;
						}
				}
			}
			if(strcmp(argv[i], "-s") == 0){
				if(i+1 == argc || argv[i+1][0] != '/') exit(1);
				for(i++, j = 1; j < strlen(argv[i]); j++){
						if(argv[i][j] == '/'){
							char *str2 = cutstr(argv[i], j+1, strlen(argv[i])-2);
							str = cutstr(argv[i], 1, j-1);
							printf("substitute %s %s\n", str, str2);
							break;
						}
				}
				i++;
			}
		}
	}
		return 0;
}

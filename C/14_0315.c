#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

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
	char *str = (char *)malloc(sizeof(char *)*10);
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
int main(void)
{
	char *a = "abcdcg";
	char *b = "c";
	char *c = "ef";
	printf("%s, %s, %s\n", a, b, c);
	printf("%s\n", my_subst(a, b, c));
	int i = 0;
	return 0;
}

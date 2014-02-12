#include<stdio.h>

int main(int argc, char *argv[])
{
	int t;
	FILE *file;
	file = fopen(argv[1], "r");
	while(1){
		if(fscanf(file, "%d", &t) == EOF){
			printf("%d", t);
		}
	}
	fclose(file);
	return 0;
}

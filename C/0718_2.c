#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int count = 0;
    FILE  *in_file;

    int ch;

    in_file = fopen(argv[1], "r");
    if(in_file == NULL){
        printf("Cannot open %s\n", argv[1]);
        return 1;
    }

    while(1){
        ch = fgetc(in_file);
        if(ch == EOF){
            break;
        }
        count++;
    }

    printf("Number of charaters in %s is %d\n", argv[1], count);
    return 0;
}


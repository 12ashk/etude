#include<stdio.h>
#include<string.h>
#define N 6

struct person{
    char f_name[20];
    char l_name[20];
    float  height;
    float  weight;
};

int main(void)
{
    int i;
    struct person p[N];
    FILE *file;
    file = fopen("data09.txt", "r");
    for(i = 0; i < N; i++){
        fscanf(file, "%s", p[i].f_name);
        fscanf(file, "%s", p[i].l_name);
        fscanf(file, "%f", &p[i].height);
        fscanf(file, "%f", &p[i].weight);
    }
    fclose(file);

    return 0;
}


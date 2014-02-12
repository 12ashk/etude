#include <stdio.h>
#include <string.h>

#define N 6

int main(int argc, char *argv[])
{
    struct PERSON
    {
        char family_name[20];
        char given_name[20];
        float height;
        float weight;
    } p[N];
    int i;
    char s[50];
    FILE *fp;

    fp=fopen(argv[1], "r");
    if (fp==NULL)
    {
        printf("%s not found\n", argv[1]);
        return 1;
    }

    for (i=0; i<N; i++)
    {
        fscanf(fp, "%s", p[i].given_name);
        fscanf(fp, "%s", p[i].family_name);
        fscanf(fp, "%f", &p[i].height);
        fscanf(fp, "%f", &p[i].weight);
    }
    fclose(fp);

    for (i=0; i<N; i++)
    {
        printf("%s %s %f %f\n", p[i].given_name, p[i].family_name, p[i].height, p[i].weight);
    }

    return 0;
}

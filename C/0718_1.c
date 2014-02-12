#include<stdio.h>

#define MAX_ENTRIES 3

struct mailing{
    char name[60];
    char adress1[60];
    char adress2[60];
    char city[40];
    char state[2];
    long int zip;
};

int main(void)
{
    struct mailing *list_ptrs[MAX_ENTRIES];
    int current;

    for(current = 0; current < MAX_ENTRIES; current++){
        list_ptrs[current] = &list[current];
    }

    return 0;
}

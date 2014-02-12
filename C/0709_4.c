#include<stdio.h>
#include<string.h>

struct bin
{
    char name[30];
    int quantity;
    int cost;
};

int main(void)
{
    struct bin printer_cable_bin;

    strcpy(printer_cable_bin.name, "printer Cable");
    printer_cable_bin.quantity = 0;
    printer_cable_bin.cost = 1295;
    printf("%d\n", printer_cable_bin.cost);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long get_answer0(int supremum) {
    if (supremum < 3)
        return 0;
    long sum = 2;
    int t = 3, f, i;
    while (t < supremum) {
        f = 1;
        for (i = 3; i * i <= t; i += 2)
            if (t % i == 0) {
                f = 0;
                break;
            }
        if (f)
            sum += t;
        t += 2;
    }
    return sum;
}

long get_answer1(int supremum) {
    if (supremum < 3)
        return 0;
    int judge[supremum];
    int i, j;
    for (i = 2; i < supremum; i++)
        judge[i] = 1;
    long sum = 0;
    for (i = 2; i < supremum; i++) {
        if (judge[i] == 0)
            continue;
        sum += i;
        for (j = i + i; j < supremum; j += i)
            judge[j] = 0;
    }
    return sum;
}

int main(void) {
    long ans;
    ans = get_answer1(2000);
    printf("%ld\n", ans);
    return 0;
}

// https://atcoder.jp/contests/abc377/tasks/abc377_a
#include "stdio.h"

int main() {
    char s[3];
    int f[3] = {0};
    scanf("%s", s);
    for (int i = 0; i < 3; i++) {
        if (s[i] - 'A' <= 2) f[s[i] - 'A'] = 1;
    }
    if ((f[0] + f[1] + f[2]) == 3)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

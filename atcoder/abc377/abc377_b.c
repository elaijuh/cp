// https://atcoder.jp/contests/abc377/tasks/abc377_b
#include "stdio.h"

int main() {
    char s[8][8];
    for (int i = 0; i < 8; i++) scanf("%s", s[i]);

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (s[i][j] == '#') {
                for (int k = 0; k < 8; k++) {
                    if (s[i][k] == '.') s[i][k] = '@';
                    if (s[k][j] == '.') s[k][j] = '@';
                }
                continue;
            }
    int r = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (s[i][j] == '.') r++;

    printf("%d\n", r);
    return 0;
}

// https://qoj.ac/submission/696858
// 0ms
#include "stdio.h"

char s[100000000];

int main() {
    int n, m;
    int p = 0;
    for (int i = 0; i < 10000000; ++i) {
        s[p++] = 49;
        s[p++] = 49;
        s[p++] = 49;
        s[p++] = 49;
        s[p++] = 49;
        s[p++] = 49;
        s[p++] = 49;
        s[p++] = 49;
        s[p++] = 49;
        s[p++] = '\n';
    }
    fwrite(s, 1, p, stdout);
    return 0;
}

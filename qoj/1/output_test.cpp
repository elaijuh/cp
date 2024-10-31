#include <bits/stdc++.h>

char s[100'000'000];

int main() {
    int n, m;
    int p = 0;
    for (int i = 0; i < 10'000'000; ++i) {
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
    // fwrite(s, 1, p, stdout);
    return 0;
}

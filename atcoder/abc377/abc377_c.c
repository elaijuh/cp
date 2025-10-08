// https://atcoder.jp/contests/abc377/tasks/abc377_c
// #paring function #hash
// https://en.wikipedia.org/wiki/Pairing_function#Cantor_pairing_function

#include "stdint.h"
#include "stdio.h"

#define cantor(x, y) ((x + y) * (x + y + 1) / 2 + y)
#define HASH 1800017

struct pair {
    long x, y;
    int next;
} p[1800000];

int ht[HASH];
long n, r;

void func(long x, long y) {
    int i, j, k;
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    i = cantor(x, y) % HASH;
    j = ht[i];
    if (j < 0) {
        p[r].x = x;
        p[r].y = y;
        p[r].next = -1;
        ht[i] = r++;
        return;
    }
    while (j >= 0 && (p[j].x != x || p[j].y != y)) {
        k = j;
        j = p[j].next;
    }
    if (j < 0) {
        p[r].x = x;
        p[r].y = y;
        p[r].next = -1;
        p[k].next = r++;
    }
    return;
}

int main() {
    int m;
    scanf("%ld %d", &n, &m);
    int d[8][2] = {{2, 1},   {1, 2},   {-1, 2}, {-2, 1},
                   {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    r = 0;
    for (int i = 0; i < HASH; i++) ht[i] = -1;
    while (m--) {
        long x, y;
        scanf("%ld %ld", &x, &y);
        func(x - 1, y - 1);
        for (int k = 0; k < 8; k++) {
            func(x - 1 + d[k][0], y - 1 + d[k][1]);
        }
    }

    printf("%ld\n", n * n - r);
    return 0;
}

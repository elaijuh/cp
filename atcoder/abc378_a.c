// https://atcoder.jp/contests/abc378/tasks/abc378_a
#include "stdio.h"

int main() {
    int s[5] = {0};
    int a;
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &a);
        s[a]++;
        if (s[a] == 2) {
            s[a] = 0;
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}

// http://www.spoj.com/problems/CODEIT03/
#include <stdio.h>

int leap(y) {
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
}

int main() {
    int t, d, m, y, i, r;
    char* day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d", &t);
    while (t--) {
        r = 0;
        scanf("%d %d %d", &d, &m, &y);

        // days in this month
        r += d;

        // days in this year till last month
        for (i = 0; i < m - 1; i++)
            r += days[i];
        if (m > 2 && leap(y))
            r++;

        // days from 1/1/2012 to 31 Dec last year
        r += (y - 2012) * 365;
        for (i = 2012; i < y; i+=4)
            if (leap(i))
                r++;
        r--;

        printf("%s\n", day[r % 7]);
    }
}

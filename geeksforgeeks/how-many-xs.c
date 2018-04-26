// https://practice.geeksforgeeks.org/problems/how-many-xs/0
#include <stdio.h>
#include <math.h>

int main() {
    int t, x, l, u;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        scanf("%d %d", &l, &u);
        int c = 0;
        for(int i=l+1; i<=u-1; i++)
        {
            int j = i;
            while(j>0)
            {
                if(j%10==x)
                    c++;
                j/=10;
            }
        }
        printf("%d \n", c);
    }

}

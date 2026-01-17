t = int(input())
for _ in range(t):
    ans = 0
    s, k, m = map(int, input().split())
    flips = m // k
    mleft = m % k
    if k >= s:
        ans = s - mleft if s > mleft else 0
    else:
        if flips % 2 == 1:
            ans = k - mleft if k > mleft else 0
        else:
            ans = s - mleft if s > mleft else 0
    print(ans)

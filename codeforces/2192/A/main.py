t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    ans = 1
    for i in range(1, n):
        if s[i] != s[i - 1]:
            ans += 1
    if s[0] != s[-1]:
        ans += 1
    print(min(n, ans))

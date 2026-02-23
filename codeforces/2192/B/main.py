import sys

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    cnt0 = s.count("0")
    cnt1 = s.count("1")
    if cnt0 & 1:
        print(cnt0)
        print(" ".join([str(i + 1) for i, c in enumerate(s) if c == "0"]))
    elif not cnt1 & 1:
        print(cnt1)
        if cnt1:
            print(" ".join([str(i + 1) for i, c in enumerate(s) if c == "1"]))
    else:
        print(-1)

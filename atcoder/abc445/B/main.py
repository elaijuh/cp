N = int(input())
S = [input() for _ in range(N)]
m = 0
for s in S:
    m = max(m, len(s))
for s in S:
    print(s.center(m, "."))

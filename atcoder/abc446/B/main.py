N, M = map(int, input().split())
taken = set()
for _ in range(N):
    L = int(input())
    X = map(int, input().split())
    f = False
    for x in X:
        if x not in taken:
            taken.add(x)
            print(x)
            f = True
            break
    if not f:
        print(0)

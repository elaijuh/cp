import sys
from collections import deque

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N, D = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    q = deque()
    for i in range(N):
        q.append((A[i], i))
        while q and B[i] != 0:
            egg, day = q[0]
            q.popleft()
            if egg >= B[i]:
                egg -= B[i]
                B[i] = 0
                q.appendleft((egg, day))
            else:
                B[i] -= egg
        if q[0][1] == i - D:
            q.popleft()
    print(sum(x[0] for x in q))

t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    if y >= 0:
        t = x - 2 * y
        pass
    else:
        t = x + 4 * y
        pass
    if t < 0:
        print("NO")
        continue
    if t % 3 != 0:
        print("NO")
        continue
    print("YES")

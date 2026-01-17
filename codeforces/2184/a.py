t = int(input())
for _ in range(t):
    n = int(input())
    print(n if n <= 3 else n % 2)

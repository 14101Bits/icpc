N, M= map(int, input().split())
yoko = []
for i in range(N):
    s = str(input())
    if 'x' in s:
        if (len(set(s))) == 1:
            print(f"Faucet {i+1}")
        else:
            ans = s.index("x")
            print(f"Drain {ans+1}")
            break

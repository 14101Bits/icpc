N = int(input())
ans = 0
for i in range(N):
    A, B, S = input().split()
    A = int(A)
    B = int(B)
    sa = B - A
    if S == 'keep' : ans += sa

print(ans)
N = int(input())
C = list(map(int, input().split()))

L = [0] * N
R = [0] * N

for i in range(N):
    if i > 0 and C[i] == C[i-1]:
        L[i] = L[i-1]
    else:
        L[i] = i

for i in range(N-1, -1, -1):
    if i < N-1 and C[i] == C[i+1]:
        R[i] = R[i+1]
    else:
        R[i] = i

ans = []

for i in range(N):
    d = N
    if L[i] != 0:
        d = min(d, i - L[i] + 1)
    if R[i] != N-1:
        d = min(d, R[i] - i + 1)
    ans.append(d)

print(*ans)
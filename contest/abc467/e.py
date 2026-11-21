from cmath import inf

N,M = map(int,input().split())

A = list(map(int,input().split()))
B = list(map(int,input().split()))

ans = float(inf)

for start in range(M):
    cnt = 0
    first = start

    cnt +=(first-A[0])% M

    for i in range(N-1):
        second = (B[i] - first) % M
        cnt += (second-A[i+1])% M
        first = second

    ans = min(ans,cnt)

print(ans)
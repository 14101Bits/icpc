N,M = map(int,input().split())

A = list(map(int,input().split()))
B = list(map(int,input().split()))

ans = N

for start in range(2):
    cnt = 0
    first = start

    if first != A[0]:
        cnt += 1

    for i in range(N-1):
        second = (B[i] - first) % 2

        if second != A[i+1]:
            cnt += 1

        first = second

    ans = min(ans,cnt)

print(ans)
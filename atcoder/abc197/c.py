N = int(input())
A = list(map(int,input().split()))

ans = 10**18

for mask in range(1<<(N-1)):
    xor_sum = 0
    cur_or = 0

    for i in range(N):
        cur_or|= A[i]
        if i == N - 1 or (mask>>i)&1:
            xor_sum ^= cur_or
            cur_or = 0

    ans = min (xor_sum,ans)


print(ans)

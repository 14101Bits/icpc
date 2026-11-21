#https://atcoder.jp/contests/dp/tasks/dp_o
# 0<N<21
import sys
input = sys.stdin.readline
MOD = 10**9 + 7

N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]

good = [0] * N

for i in range(N):
    for j in range(N):
        if A[i][j] == 1:
            good[i] |= 1 << j

dp = [0] * (1 << N)
dp[0] = 1

for mask in range(1 << N):
    man = mask.bit_count()

    if man == N:
        continue

    can = good[man] & ~mask

    while can:
        bit = can & -can
        nxt = mask | bit
        dp[nxt] += dp[mask]
        dp[nxt] %= MOD
        can -= bit

print(dp[(1 << N) - 1])
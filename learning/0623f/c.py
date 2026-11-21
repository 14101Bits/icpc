import sys
input = sys.stdin.readline
#https://atcoder.jp/contests/abc265/tasks/abc265_e
MOD = 998244353
border = 10**9

N = int(input())

arr = input().split()

pairs = []
for i in range(0, len(arr), 2):
    a = arr[i]
    b = arr[i + 1]
    pairs.append((a, b))

all_border = 2 *border
dp = [[0] * all_border for _ in range(all_border)]

def ifout (x):
    return (x >= -all_border)

def canGo(canx,cany,posx,posy):
    return (posx - canx)

for i in range(all_border):
    for j in range(all_border):
        if (i,j) in pairs:
            dp[i][j] = 0
            continue

        if i > -all_border:
            dp[i][j] += dp[i - pairs[0][0]][j-pairs[0][1]]

        if j > 0:
            dp[i][j] += dp[i][j - 1]

        dp[i][j] %= MOD

print(dp[H - 1][W - 1])
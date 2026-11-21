N, K = map(int, input().split())

base = 0
C = []

for _ in range(N):
    A, B = map(int, input().split())
    base += A
    C.append(B - A)

NEG = -(10**30)

dp = [NEG] * (2 * K + 1)
dp[0] = 0

for x in C:
    ndp = [NEG] * (2 * K + 1)

    for j in range(2 * K + 1):
        if dp[j] == NEG:
            continue
        if j % 2 == 0:
            ndp[j] = max(ndp[j], dp[j])
        else:
            ndp[j] = max(ndp[j], dp[j] + x)

        if j + 1 <= 2 * K:
            if (j + 1) % 2 == 1:
                ndp[j + 1] = max(ndp[j + 1], dp[j] + x)
            else:
                ndp[j + 1] = max(ndp[j + 1], dp[j])

    dp = ndp

print(base + max(dp))
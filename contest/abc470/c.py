N, Q = map(int, input().split())

nums = [0] * N
ans = 0

for _ in range(Q):
    a = list(map(int, input().split()))

    if a[0] == 1:
        x = a[1] - 1

        ans ^= nums[x]
        nums[x] += 1
        ans ^= nums[x]

    else:
        cnt = 0
        for x in range(N):
            if nums[x] == 0:
                continue
            else:
                cnt += 1
                nums[x] -= 1
        bit = cnt % 2
        if (cnt == 1):
            ans ^= ((1 << 20) - 1)

    print(ans)
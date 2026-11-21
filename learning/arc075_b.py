N, A, B = map(int, input().split())
H = [int(input()) for _ in range(N)]

left = 0
right = 10**9

while right - left > 1:
    mid = (left + right) // 2

    count = 0

    for h in H:
        remaining = h - mid * B

        if remaining > 0:
            count += (remaining + A - B - 1) // (A - B)

    if count <= mid:
        right = mid
    else:
        left = mid

print(right)
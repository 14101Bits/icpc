A, B, X = map(int, input().split())

left = 0
right = 10**9 + 1

while right - left > 1:
    mid = (left + right) // 2

    price = A * mid + B * len(str(mid))

    if price <= X:
        left = mid
    else:
        right = mid

print(left)
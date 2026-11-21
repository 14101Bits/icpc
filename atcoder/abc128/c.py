N, M = map(int, input().split())

lists = []

for _ in range(M):
    arr = list(map(int, input().split()))
    switches = arr[1:]

    mask = 0
    for s in switches:
        s -= 1
        mask |= 1 << s

    lists.append(mask)

p = list(map(int, input().split()))

ans = 0

for state in range(1 << N):
    ok = True

    for i in range(M):
        on_count = (state & lists[i]).bit_count()

        if on_count % 2 != p[i]:
            ok = False
            break

    if ok:
        ans += 1

print(ans)
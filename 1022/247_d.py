from collections import deque

n = int(input())
q = deque()

for _ in range(n):
    res = list(map(int, input().split()))
    ope = res[0]

    if ope == 1:
        x, c = res[1], res[2]
        q.append((x, c))

    elif ope == 2:
        c = res[1]
        ans = 0

        while c > 0:
            x, cnt = q.popleft()
            take = min(c, cnt)

            ans += x * take
            c -= take

            if cnt > take:
                q.appendleft((x, cnt - take))

        print(ans)
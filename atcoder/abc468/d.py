s = input()
n = len(s)
ans = 0

for k in range(2):
    for st in range(n):
        l = st - k
        r = st
        cnt = 0

        while 0 <= l and r < n:
            if s[l] != s[r]:
                cnt += 1

            if cnt >= 2:
                break

            ans += 1
            l -= 1
            r += 1

print(ans)
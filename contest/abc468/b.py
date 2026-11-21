
m,d = map(int,input().split())
s = str(input())
now = 0
ans = 0

for i in range(m):
    if (s[i] == '.'):
        now += 1
    if (s[i] == 'G'):
        if (now > 0 ):
            now = max(0,now-d)
            ans += now
        now = -d

ans += max(0, now)
print(ans)



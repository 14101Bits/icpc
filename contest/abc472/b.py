
N = int(input())
l = list(map(int, input().split()))


left = l[0]

right = 0

for i in range(1,N):
    right += l[i]


sa = max(right-left,left-right)

ans = sa

for i in range(1,N):
    left += l[i]
    right -= l[i]
    ans = min(max(right - left, left - right),ans)

print(ans)

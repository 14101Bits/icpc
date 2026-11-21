n,k=map(int,input().split())
a = list(map(int,input().split()))
res = 0
points = set()
for i in range(n-1):
    now = a[i]
    nxt = a[i+1]

    if now == k:
        points.add(i)
    if nxt == k:
        points.add(i+1)
    if min(now, nxt) < k < max(now, nxt):
        points.add(i+0.5)

print(len(points))
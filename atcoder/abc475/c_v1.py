N,S,L = map(int, input().split())
roads= list(map(int, input().split()))
right = 1
ans = 1
left = S-1
start = S-1
now = S - 1
cost = L


next_road = roads[now]
while (next_road <= cost ):
    ans += 1
    cost -= next_road
    now += 1
    if(now==N-1):
        break
    else:
        next_road = roads[now]

if (start>0):
    while(left):
        if 2*

print(ans)


n,q = map(int,input().split())
colors = ['a'for _ in range(n)]
tiles = [False for _ in range(n)]

now_color = 'a'
for i in range(q):
    k1,k2 = map(str,input().split())
    if (k1=='1'):
        pos =int(k2)-1
        tiles[pos] = not tiles[pos]
        if (tiles[pos]):
            colors[pos] = now_color
    elif (k1=='2'):
        now_color = k2

for s in range(n):
    if not tiles[s]:
        colors[s] = now_color

print(*colors,sep='')
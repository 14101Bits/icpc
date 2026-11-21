from sys import setrecursionlimit

H, W, K = map(int, input().split())

columns = []
#soto ni iku

for _ in range(H):
    columns.append(list(input()))

safe = []
ans = set()
candi = set()

dan_r =set()
dan_c =set()


for r in range(H):
    for c in range(W):
        if columns[r][c] == '#':
            dan_c.add(c)
            dan_r.add(r)


for r in range(H):
    for c in range(W):
        if r in dan_r or c in dan_c:
            continue
        else:
            safe.append((r,c))
            ans.add((r,c))


def go_next(r,c,step):
    if columns[r][c] == '#':
        return
    else:
        ans.add((r,c))
    if step == 0:
        return
    else:
        if c>0:
            go_next(r,c-1,step-1)
        if c<W-1:
            go_next(r,c+1,step-1)
        if r>0:
            go_next(r-1,c,step-1)
        if r<H-1:
            go_next(r+1,c,step-1)

setrecursionlimit(10**7)

for (sr,sc) in safe:
    go_next(sr,sc,K)

#触发了python的递归深度


print(len(ans))
N = int(input())
masks = []
for i in range(N):
    A =  int(input())
    person = []
    for j in range(A):
        x,y = map(int,input().split())
        x-=1
        person.append((x,y))
    masks.append(person)


ans = 0
for state in range(1<<N):
    ok = True
    for i in range(N):
        if not (state >> i & 1 ):
            continue
        for x,y in masks[i]:
            actual = (state >>x) & 1
            if actual !=y:
                ok = False
                break
        if not ok:break
    if ok : ans = max (ans,state.bit_count())
print(ans)


T = int(input())
INF = 10**18
ans = []
for _ in range(T):
    X,Y,K = map(int, input().split())
    cnt = 0
    while (X!=Y):
        if X<Y:
            i = X
            X = Y
            Y = i
        X = X//K
        cnt += 1
    ans.append(cnt)

for i in ans:
    print(i)
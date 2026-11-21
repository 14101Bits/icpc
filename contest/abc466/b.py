N,M=map(int,input().split())
ans = [-1 for _ in range(M)]
for i in range(N):
    C,S = map(int,input().split())
    if (ans[C-1]<S):
        ans[C-1]=S
print(*ans)
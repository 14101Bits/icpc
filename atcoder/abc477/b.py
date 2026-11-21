n,d=map(int,input().split())
X = list(map(int,input().split()))
ans = list()

for ppl in range(0,n):
    st = X[ppl]
    for i in range(0,n):
        sa = max(st-X[i],X[i]-st)
        if sa<d and i!=ppl:
            break
        if (i==n-1):
            ans.append(ppl+1)

print(len(ans))
print(*ans,sep=' ')

n = int(input())
a = list(map(int,input().split()))
ans = 0
for i in range(1,n-1):
    left = a[i-1]
    mid = a[i]
    right = a[i+1]
    if (mid > left)and(mid > right):
        ans +=1

print(ans)
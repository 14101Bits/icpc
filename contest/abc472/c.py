n,m,k = map(int,input().split())
f = list(map(int,input().split()))
# d = 0 ~ N-1 max(i-M,0)

sum = 0
for i in range(n):
    left = max(i-m,0)
    to_eat = f[i]
    if (i-m>=0):
        sum -= f[i-m]
    sum += to_eat
    if sum>k:
        print("No")
        f[i]=0
        sum -= to_eat
    else:
        print("Yes")

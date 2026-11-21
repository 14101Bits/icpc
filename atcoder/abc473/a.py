N = int(input())
a = list(map(int, input().split()))

half = N/2
mid = int(half)
sum = 0
for i in range(mid,N):
    sum += a[i]

print(sum)
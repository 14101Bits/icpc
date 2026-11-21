N = int(input())
goods = list(map(int, input().split()))
ans = [0,0,0] #1,10,100

for good in goods:
    while(good>=1000):
        good -= 1000
    if(good!=0):
        good = 1000-good
    ans[0]+=good % 10
    ans[1]+=(good//10) % 10
    ans[2]+=(good//100) % 10

print(*ans)
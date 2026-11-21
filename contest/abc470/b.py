N = int(input())
C = list(map(int, input().split()))
cnt = list(0 for _ in range(N))

for i in C:
    cnt[i-1]+=1

max = max(cnt)

print(N-max)

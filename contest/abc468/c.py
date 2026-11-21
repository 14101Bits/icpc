from itertools import permutations

n = int(input())
p = tuple(map(int, input().split()))
q = tuple(map(int, input().split()))

ans = 0

for r in permutations(range(1, n + 1)):
    if p < r < q:
        ans += 1

print(ans)
N = int(input())
S = input()
from collections import deque
dq = deque()
right = True

for i in range(1,N+1):
    if (right):
        dq.append(i)
    else:
        dq.appendleft(i)

    if S[i-1] == 'o':
        right = not(right)

ans = list(dq)

if not right:
    ans.reverse()

print(*ans)
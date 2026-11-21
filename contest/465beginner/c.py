N = int(input())
S = input()

A = [i for i in range(1,N+1)]

for i in range(N):
    if S[i] == 'o':
        A[:i + 1] = reversed(A[:i + 1])



print(*A)
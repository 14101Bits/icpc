N,M=map(int,input().split())

op = []
row = set()
column = set()

ans = 0

for i in range(M):
    op.append(tuple(map(int,input().split())))

for R,C in reversed(op):
    if R not in row and C not in column:
        ans+= 1
    row.add(R)
    column.add(C)
print(ans)



q = int(input())
index = {}
for _ in range(q):
    acc = str(input())
    if acc not in index:
        index[acc] = len(index)
    print(index[acc]+1)
q =int(input())
s = str(input())
T = str(input())

import bisect
indexes = []
start = 0

while True:
    i = s.find(T, start)
    if i == -1:
        break
    indexes.append(i)
    start = i + 1

for i in range(q):
    l,r = map(int,input().split())
    pos = bisect.bisect_left(indexes, l-1)
    if pos < len(indexes) :
        index_pos = indexes[pos]
        if r>=index_pos+len(T):
            print("Yes")
            continue
    print("No")


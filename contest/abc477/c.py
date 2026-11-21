q =int(input())
s = str(input())
T = str(input())

for i in range(q):
    l,r = map(int,input().split())
    wenzi = s[l-1:r]
    if T in wenzi:
        print("Yes")
    else:
        print("No")


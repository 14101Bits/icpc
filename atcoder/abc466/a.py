N = int(input())
X = list(map(int, input().split()))
for ans in X:
    if (ans>=0):
        print("No")
        break

else:
    print("Yes")
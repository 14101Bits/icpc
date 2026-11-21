N = int(input())

def question(i,j):
    print("?",i,j,flush=True)
    return input().strip()

def ans(i):
    print("!", i, flush=True)

left = 1
right = 2
cnt = 0

for right in range(2,N+1):
    while left < right:
        answer = question(left,right)

        if answer == "Yes":
            break
        else:
            left += 1
    cnt += right-left
ans(cnt)
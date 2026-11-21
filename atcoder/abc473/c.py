
a = list(map(int, input().split()))

stu = [0] * K

for i in range(N):
    cla = a[i] - 1
    stu[cla] += 1

sorted_stu = sorted(stu, reverse=True)
#print(sorted_stu)
largest = sorted_stu[0]
if (K>1):
    next = largest - 1
    sum = 0
    for j in range(K):
        if sorted_stu[j]== largest or sorted_stu[j]== next:
            sum +=1
        else:
            break
    print(sum)
else:
    print(1)
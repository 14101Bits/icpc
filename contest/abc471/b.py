N = int(input())
dict = {}
for i in range(N):
    ans = str(input()).lower()
    if (ans not in dict):
        dict[ans] = 1
    else:
        dict[ans] += 1

sorted_dict = sorted(dict.items(), key=lambda d: d[1],reverse=True)

print(sorted_dict[0][1])

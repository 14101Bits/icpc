N = int(input())
cookies = list(map(int, input().split()))
max = 10000000000

if (0 not in cookies):
    cookies.append(0)

sorted_cookies = sorted(cookies)


index = sorted_cookies.index(0)
ans = 0

length = len(sorted_cookies)
for _ in range(length-1):
    #print(index)
    left = right = max
    if (index > 0):
        left = sorted_cookies[index]-sorted_cookies[index - 1]
    if (index < len(sorted_cookies) - 1):
        right = sorted_cookies[index + 1]-sorted_cookies[index]
    sorted_cookies.remove(sorted_cookies[index])
    #print(left, right)
    if (right < left):
        ans += right
    else:
        ans += left
        index -= 1


print(ans)
s = str(input())
ans = ""
for i in range(len(s)):
    ans += s[i]
    if i!=(len(s)-1):
        ans += 'o'

print(ans)
s = str(input())
ans = ""
for char in s:
    if char != 'A':
        ans+='.'
    else:
        ans+='A'

print(ans)
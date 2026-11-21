a,b = map(int, input().split())

ans = "Nein"

if (a + b == 9):
    ans = "Nine"
elif(a - b == 9):
    ans = "Nine"
elif(a * b == 9):
    ans = "Nine"
elif (a / b == 9):
    ans = "Nine"

print(ans)
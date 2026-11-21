#从后往前找3然后找对应的key这样往前找

N,Q = map(int,input().split())

commands = []

for _ in range(Q):
    command = input().split()

    t = int(command[0])
    p = int(command[1])

    if t == 2:
        s = command[2]
        commands.append((t, p, s))
    else:
        commands.append((t, p))

now = -1
ans = []

for command in reversed(commands):
    t = command[0]
    p = command[1]
    if t == 3:
        if now == -1:
            now = p
    elif t == 1:
        if now == p:
            now = -1
    elif t == 2:
        s = command[2]
        if now == p:
            ans.append(s)

print("".join(reversed(ans)))

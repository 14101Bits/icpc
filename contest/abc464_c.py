N,M = int(input().strip())

all_bird = []
for _ in range(N):
    A,D,B = int (input().strip())
    colors = []
    for day in range(M):
        if (day <= D-1):
            colors.append(A)
        else:
            colors.append(B)

    all_bird.append(colors)

for day in range(M):
    color = ()
    for i in range(N):
        color.append(all_bird[i][day])

    print(len(color))

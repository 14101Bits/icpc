T = int(input())
for _ in range(T):
    p_x,p_y,q_x,q_y,r_x,r_y,s_x,s_y = map(int,input().split())

    dx1 = q_x - p_x
    dy1 = q_y - p_y
    dx2 = s_x - r_x
    dy2 = s_y - r_y

    if dx1 * dy2 != dy1 * dx2:
        print("Yes")
    else:
        mid_x = r_x + s_x - p_x - q_x
        mid_y = r_y + s_y - p_y - q_y

        if dx1 * mid_x + dy1 * mid_y == 0:
            print("Yes")
        else:
            print("No")
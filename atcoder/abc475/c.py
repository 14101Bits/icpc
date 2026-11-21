N,S,L = map(int, input().split())
roads= list(map(int, input().split()))
right = S-1
left = S-1
cost = L
goleftroads =[0] * (N-1)
gorightroads =[0] * (N-1)
for i in range(N-1):
    gorightroads[i] = roads[i]
    goleftroads[i] = roads[i]
    if (i<S-1):
        gorightroads[i] += roads[i]
    else:
        goleftroads[i] += roads[i]

def get_ans(start:int,roads:list,cost):
    left = start-1
    right = start
    while (left >= 0 or right < len(roads)) and cost> 0:
        if left < 0:
            if (roads[right]<=cost):
                cost -= roads[right]
                right+=1
            else:
                break
        elif right >= len(roads):
            if (roads[left]<=cost):
                cost -= roads[left]
                left -= 1
            else:
                break
        elif roads[left] <= roads[right]:
            if (roads[left]<=cost):
                cost -= roads[left]
                left -= 1
            else:
                break
        else:
            if (roads[right]<=cost):
                cost -= roads[right]
                right+=1
            else:
                break
    return(right-left)

ans = max(get_ans(S-1,gorightroads,L),get_ans(S-1,goleftroads,L))
print(ans)
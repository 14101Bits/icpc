import sys
input = sys.stdin.readline
from heapq import heappush, heappop
from math import inf

N, M, Y = map(int, input().split())
G = [[] for _ in range(N + 3)]  # [[des_node,cost]]
IN = N + 1  # W_IN
OUT = N + 2  # W_OUT

G[IN].append((OUT, Y))

for _ in range(M):
    u, v, T = map(int, input().split())
    G[u].append((v, T))
    G[v].append((u, T))

x = list(map(int, input().split()))  # N

for i in range(1, N + 1):
    G[i].append((IN, x[i - 1]))
    G[OUT].append((i, x[i - 1]))


def dijkstra(G, start):
    dist = [inf] * len(G)  # ?
    dist[start] = 0
    heap = []
    heappush(heap, (0, start))

    while heap:
        cost, v = heappop(heap)

        if dist[v] < cost:
            continue

        for next_v, edge_cost in G[v]:
            new_cost = cost + edge_cost

            if new_cost < dist[next_v]:
                dist[next_v] = new_cost
                heappush(heap, (new_cost, next_v))
    return dist


dist = dijkstra(G, 1)

print(*dist[2:N + 1])

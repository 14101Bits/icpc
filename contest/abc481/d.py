n,m,s,t=map(int,input().split())
import heapq

from collections import defaultdict

graph = defaultdict(list)

for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append((b,1))

for u, edges in graph.items():
    if not edges:
        continue

    i = min(range(len(edges)), key=lambda i: edges[i][0])
    v, w = edges[i]
    edges[i] = (v, 0)

def dijkstra(start, end):
    pq = [(0, start)]
    dist = {start: 0}

    while pq:
        d, node = heapq.heappop(pq)

        if d > dist[node]:
            continue

        if node == end:
            return d

        for nxt, weight in graph[node]:
            nd = d + weight

            if nd < dist.get(nxt, float('inf')):
                dist[nxt] = nd
                heapq.heappush(pq, (nd, nxt))

    return -1

print(dijkstra(s,t))
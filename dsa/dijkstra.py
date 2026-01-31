import heapq
from typing import List


def dijkstra(start: int, graph: List[List[(int, int)]]) -> List[int]:
    n = len(graph)
    min_weight = [float("inf")] * n
    min_weight[start] = 0
    pq = [(0, start)]
    while pq:
        cw, u = heapq.heappop(pq)
        # shorter path already found
        if cw > min_weight[u]:
            continue
        for v, w in graph[u]:
            nw = cw + w
            if nw < min_weight[v]:
                min_weight[v] = nw
                heapq.heappush(pq, (nw, v))
    return min_weight


if __name__ == "__main__":
    # directed weighted graph represented by edges
    edges = [[0, 1, 3], [3, 1, 1], [2, 3, 4], [0, 2, 2]]
    # represented by adjacency list
    adj = [[] for _ in range(4)]
    for u, v, w in edges:
        adj[u].append((v, w))
    print(dijkstra(0, adj))

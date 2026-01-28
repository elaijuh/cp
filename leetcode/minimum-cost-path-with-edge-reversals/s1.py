import heapq
from typing import List
from collections import defaultdict


class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        g = defaultdict(list)
        for u, v, w in edges:
            g[u].append((v, w))
            g[v].append((u, w * 2))
        # dijkstra
        dis = [float("inf")] * n
        dis[0] = 0
        pq = [(0, 0)]
        while pq:
            cost, u = heapq.heappop(pq)
            if cost > dis[u]:
                continue
            if u == n - 1:
                return cost
            for v, w in g[u]:
                new_cost = cost + w
                if new_cost < dis[v]:
                    dis[v] = new_cost
                    heapq.heappush(pq, (new_cost, v))
        return -1

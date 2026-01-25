from typing import List
from collections import defaultdict, deque


class Solution:
    def specialNodes(
        self, n: int, edges: List[List[int]], x: int, y: int, z: int
    ) -> int:
        # tree is represented as adjacency list
        tree = defaultdict(list)
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)

        def bfs(root) -> List[int]:
            vis = set([root])
            q = deque([root])
            d = [0] * n
            l = 0
            while q:
                for _ in range(len(q)):
                    node = q.popleft()
                    d[node] = l
                    for neighbour in tree[node]:
                        if neighbour not in vis:
                            vis.add(neighbour)
                            q.append(neighbour)
                l += 1
            return d

        px = bfs(x)
        py = bfs(y)
        pz = bfs(z)
        ans = 0
        for i in range(len(px)):
            if (
                px[i] ** 2 + py[i] ** 2 == pz[i] ** 2
                or px[i] ** 2 + pz[i] ** 2 == py[i] ** 2
                or py[i] ** 2 + pz[i] ** 2 == px[i] ** 2
            ):
                ans += 1
        return ans

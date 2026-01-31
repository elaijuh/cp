from typing import List


class Solution:
    def minimumCost(
        self,
        source: str,
        target: str,
        original: List[str],
        changed: List[str],
        cost: List[int],
    ) -> int:
        # floyd-warshall
        adj = [[float("inf")] * 26 for _ in range(26)]
        for x, y, c in zip(original, changed, cost):
            adj[ord(x) - ord("a")][ord(y) - ord("a")] = min(
                adj[ord(x) - ord("a")][ord(y) - ord("a")], c
            )
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])

        ans = 0
        for x, y in zip(source, target):
            if x != y:
                cost = adj[ord(x) - ord("a")][ord(y) - ord("a")]
                if cost == float("inf"):
                    return -1
                ans += cost
        return ans

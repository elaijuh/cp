from typing import List


class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        points = [(i, j) for i in range(m) for j in range(n)]
        # sort points by value
        points.sort(key=lambda p: grid[p[0]][p[1]])
        cost = [[float("inf")] * n for _ in range(m)]
        for t in range(k + 1):
            min_cost = float("inf")
            # calculate cost[i][j] for teleport from (i,j) to (x,y) given all grid[x][y]<=grid[i][j]
            j = 0
            for i in range(len(points)):
                pi, pj = points[i]
                min_cost = min(min_cost, cost[pi][pj])
                if i < len(points) - 1:
                    pii, pjj = points[i + 1]
                    if grid[pi][pj] == grid[pii][pjj]:
                        i += 1
                        continue
                for r in range(j, i + 1):
                    cost[points[r][0]][points[r][1]] = min_cost
                j = i + 1

            # calculate cost[i][j] for move right or down
            for i in range(m - 1, -1, -1):
                for j in range(n - 1, -1, -1):
                    # init state
                    if i == m - 1 and j == n - 1:
                        cost[i][j] = 0
                        continue
                    if i != m - 1:
                        cost[i][j] = min(cost[i][j], cost[i + 1][j] + grid[i + 1][j])
                    if j != n - 1:
                        cost[i][j] = min(cost[i][j], cost[i][j + 1] + grid[i][j + 1])
        return cost[0][0]

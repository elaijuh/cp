from typing import List
from collections import defaultdict


class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        e = min(m, n)
        rowsum = [[0] * n for _ in range(m)]
        for i in range(m):
            rowsum[i][0] = grid[i][0]
            for j in range(1, n):
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j]
        colsum = [[0] * n for _ in range(m)]
        for j in range(n):
            colsum[0][j] = grid[0][j]
            for i in range(1, m):
                colsum[i][j] = colsum[i - 1][j] + grid[i][j]

        # loop from top right (0,0)
        for edge in range(e, 1, -1):
            for i in range(m - edge + 1):
                for j in range(n - edge + 1):
                    # check rows
                    sum1 = rowsum[i][j + edge - 1] - (0 if j == 0 else rowsum[i][j - 1])
                    check = True
                    for ii in range(i + 1, i + edge):
                        sumii = rowsum[ii][j + edge - 1] - (
                            0 if j == 0 else rowsum[ii][j - 1]
                        )
                        if sumii != sum1:
                            check = False
                            break
                    if not check:
                        continue
                    # check columns
                    for jj in range(j, j + edge):
                        sumjj = colsum[i + edge - 1][jj] - (
                            0 if i == 0 else colsum[i - 1][jj]
                        )
                        if sumjj != sum1:
                            check = False
                            break
                    if not check:
                        continue
                    # check diagonals
                    d1 = d2 = 0
                    for k in range(edge):
                        d1 += grid[i + k][j + k]
                        d2 += grid[i + k][j + edge - k - 1]
                    if d1 == sum1 and d2 == sum1:
                        return edge
        return 1

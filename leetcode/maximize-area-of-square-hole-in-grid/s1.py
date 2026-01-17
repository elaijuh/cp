class Solution:
    def maximizeSquareHoleArea(
        self, n: int, m: int, hBars: List[int], vBars: List[int]
    ) -> int:
        def max_len(bars: List[int]) -> int:
            cur, ma = 1, 1
            for i in range(1, len(bars)):
                if bars[i] == bars[i - 1] + 1:
                    cur += 1
                else:
                    cur = 1
                ma = max(ma, cur)
            return ma + 1

        hBars.sort()
        vBars.sort()
        return min(max_len(hBars), max_len(vBars)) ** 2

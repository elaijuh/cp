from typing import List


class Solution:
    def bestTower(
        self, towers: List[List[int]], center: List[int], radius: int
    ) -> List[int]:
        t = [
            [x, y, q]
            for [x, y, q] in towers
            if abs(x - center[0]) + abs(y - center[1]) <= radius
        ]
        ax, ay, mq = -1, -1, -1
        for [x, y, q] in t:
            if q > mq:
                ax, ay, mq = x, y, q
            elif q == mq:
                if x < ax or x == ax and y < ay:
                    ax, ay = x, y
        return [ax, ay]

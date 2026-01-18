from typing import List
from collections import defaultdict, bisect_left


class Solution:
    def maxCapacity(self, costs: List[int], capacity: List[int], budget: int) -> int:
        n = len(costs)
        costs_sorted = sorted(zip(costs, capacity))
        cap_prefix = [0] * n
        # prefix max cap
        for i in range(n):
            cap_prefix[i] = max(cap_prefix[i - 1] if i > 0 else 0, costs_sorted[i][1])

        # one machine
        ans = 0
        i = bisect_left(costs_sorted, (budget, -1)) - 1
        print(i)
        if i >= 0:
            ans = cap_prefix[i]

        # tow machines
        for i in range(n):
            cst = costs_sorted[i][0]
            if cst >= budget:
                break
            j = bisect_left(costs_sorted, (budget - cst, -1)) - 1
            j = min(j, i - 1)
            if j >= 0:
                ans = max(ans, costs_sorted[i][1] + cap_prefix[j])

        return ans

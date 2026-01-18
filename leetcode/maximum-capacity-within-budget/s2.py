from typing import List


class Solution:
    def maxCapacity(self, costs: List[int], capacity: List[int], budget: int) -> int:
        cost_new = []
        cap_new = []
        # remove item which cost > budget
        # add budget+1 to each item cost
        for i in range(len(costs)):
            if costs[i] < budget:
                cost_new.append(costs[i] + budget + 1)
                cap_new.append(capacity[i])
        # add 2*(budget+1) to budget
        budget += 2 * (budget + 1)
        dp = [0] * (budget + 1)
        for i in range(1, len(cost_new) + 1):
            for j in range(budget, cost_new[i - 1], -1):
                dp[j] = max(dp[j], dp[j - cost_new[i - 1]] + cap_new[i - 1])
        return dp[budget]

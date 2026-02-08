from typing import List


class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        k = 3
        dp = [float("-inf")] * (k)  # up, down, up, down, ...
        res = float("-inf")

        for i in range(1, len(nums)):
            x0, x1 = nums[i - 1], nums[i]

            ndp = [float("-inf")] * k
            if x0 < x1:  # up: even phases
                ndp[0] = max(x0, dp[0]) + x1  # start new subarray
                for j in range(2, k, 2):  # extend existing
                    ndp[j] = max(dp[j], dp[j - 1]) + x1

            elif x0 > x1:  # down: odd phases
                for j in range(1, k, 2):  # extend existing
                    ndp[j] = max(dp[j], dp[j - 1]) + x1

            # else: equal => reset all dp (stay -inf)

            res = max(res, ndp[-1])
            dp = ndp

        return int(res)

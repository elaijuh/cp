from typing import List


class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        dp = [[float("-inf")] * (n2 + 1) for _ in range(n1 + 1)]
        for i in range(n1 - 1, -1, -1):
            for j in range(n2 - 1, -1, -1):
                take = nums1[i] * nums2[j]
                dp[i][j] = max(
                    take, take + dp[i + 1][j + 1], dp[i][j + 1], dp[i + 1][j]
                )

        return dp[0][0]

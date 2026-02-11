from typing import List


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        l, r, prefix = 0, 0, 0
        ans = float("inf")
        while r < n:
            prefix += nums[r]
            while prefix >= target:
                ans = min(ans, r - l + 1)
                prefix -= nums[l]
                l += 1
            r += 1

        return 0 if ans == float("inf") else ans

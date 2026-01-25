from typing import List


class Solution:
    def minimumPrefixLength(self, nums: List[int]) -> int:
        ans = 0
        for i in range(1, len(nums)):
            if nums[i] <= nums[i - 1]:
                ans = i
        return ans

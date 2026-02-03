from typing import List


class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        if nums[0] >= nums[1]:
            return False
        c = 1
        for i in range(2, n):
            if nums[i] == nums[i - 1]:
                return False
            if (nums[i - 1] - nums[i - 2]) * (nums[i] - nums[i - 1]) < 0:
                c += 1
        return c == 3

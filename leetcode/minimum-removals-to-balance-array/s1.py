from typing import List


class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()
        i, j, d = 0, 0, float("inf")
        while i <= j and j < n:
            if nums[i] * k >= nums[j]:
                d = min(d, n - j + i - 1)
                j += 1
            else:
                i += 1
        return int(d)

from typing import List


class Solution:
    def minOperations(self, nums: List[int], target: List[int]) -> int:
        return len(set([v for i, v in enumerate(nums) if v != target[i]]))

from typing import List


class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for i in range(n):
            s = set()
            f = [0, 0]
            for j in range(i, n):
                if nums[j] not in s:
                    s.add(nums[j])
                    f[nums[j] & 1] += 1
                if f[0] == f[1]:
                    res = max(res, j - i + 1)
        return res

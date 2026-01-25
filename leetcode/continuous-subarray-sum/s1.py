from typing import List


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        mp = {}
        prefix = 0
        for i in range(0, len(nums)):
            prefix += nums[i]
            r = prefix % k
            if r == 0 and i != 0:
                return True
            if r not in mp:
                mp[r] = i
            elif i - mp[r] >= 2:
                return True
        return False

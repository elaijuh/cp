from typing import List


class Solution:
    def minimumK(self, nums: List[int]) -> int:
        n = len(nums)
        s = sum(nums)
        # s/k <= nonPositive(nums,k) <= (s+nk)/k
        l = 1
        h = 1
        while True:
            if s <= l**3:
                break
            l += 1
        while True:
            if s + n * h <= h**3:
                break
            h += 1
        for k in range(l, h + 1):
            s = 0
            for num in nums:
                s += (num + k - 1) // k
            if s <= k * k:
                break
        return k

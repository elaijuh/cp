from typing import List


class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        te, to = 0, 0
        for i, num in enumerate(nums):
            if i & 1:
                to += num
            else:
                te += num
        ans = 0
        ce, co = 0, 0
        for i, num in enumerate(nums):
            if i & 1:
                co += num
                # new odd sum == new even sum?
                if co - num + te - ce == ce + to - co:
                    ans += 1
            else:
                ce += num
                # new even sum == new odd sum?
                if ce - num + to - co == co + te - ce:
                    ans += 1
        return ans

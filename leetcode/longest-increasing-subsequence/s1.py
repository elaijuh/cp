from bisect import bisect_left
from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lis = []
        for a in nums:
            if not lis or lis[-1] < a:
                lis.append(a)
            else:
                lis[bisect_left(lis, a)] = a
        return len(lis)

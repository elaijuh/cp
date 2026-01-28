from typing import List
import itertools


class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        diff = float("inf")
        ans = []
        for a, b in itertools.pairwise(arr):
            d = b - a
            if d < diff:
                ans = []
                diff = d
            if d == diff:
                ans.append((a, b))
        return ans

from typing import List
from bisect import bisect_left


class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        def test(b: int) -> int:
            lis = []
            for a in nums:
                if a & b:
                    if not lis or lis[-1] < a:
                        lis.append(a)
                    else:
                        lis[bisect_left(lis, a)] = a
            return len(lis)

        return max(test(1 << b) for b in range(30))

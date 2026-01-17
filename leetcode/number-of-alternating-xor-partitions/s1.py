from typing import List
from collections import defaultdict


class Solution:
    def alternatingXOR(self, nums: List[int], target1: int, target2: int) -> int:
        MOD = 10**9 + 7
        mp1 = defaultdict(int)
        mp2 = defaultdict(int)
        mp2[0] = 1
        x = 0
        cnt1 = cnt2 = 0
        for num in nums:
            x ^= num
            t1 = x ^ target1
            t2 = x ^ target2
            cnt1 = mp2.get(t1, 0) % MOD
            cnt2 = mp1.get(t2, 0) % MOD
            mp1[x] = (mp1[x] + cnt1) % MOD
            mp2[x] = (mp2[x] + cnt2) % MOD
        return (cnt1 + cnt2) % MOD

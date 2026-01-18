from typing import List
from collections import defaultdict


class Solution:
    def vowelConsonantScore(self, s: str) -> int:
        cntv = cntc = 0
        for c in s:
            if c in "aeiou":
                cntv += 1
            elif c.isalpha():
                cntc += 1
        return cntv // cntc if cntc > 0 else 0

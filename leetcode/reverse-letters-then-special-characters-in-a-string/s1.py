from typing import List


class Solution:
    def reverseByType(self, s: str) -> str:
        a = [x for x in s if x.isalnum()]
        b = [x for x in s if not x.isalnum()]
        na, nb = len(a), len(b)
        i, j = 0, 0
        ans = ""
        for c in s:
            if c.isalnum():
                ans += a[na - i - 1]
                i += 1
            else:
                ans += b[nb - j - 1]
                j += 1
        return ans

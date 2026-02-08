class Solution:
    def minimumDeletions(self, s: str) -> int:
        ans = 0
        b = 0
        for c in s:
            if c == "b":
                b += 1
            elif b:
                b -= 1
                ans += 1
        return ans

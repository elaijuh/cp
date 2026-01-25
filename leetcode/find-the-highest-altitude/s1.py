from typing import List


class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        ans = gain[0]
        for i in range(1, len(gain)):
            gain[i] += gain[i - 1]
            ans = max(ans, gain[i])
        return ans if ans > 0 else 0

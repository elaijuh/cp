from typing import List


class Solution:
    def countMonobit(self, n: int) -> int:
        return len([x for x in range(n + 1) if bin(x).count("0") == 1]) + 1

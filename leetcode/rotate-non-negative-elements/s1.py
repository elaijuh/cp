from typing import List


class Solution:
    def rotateElements(self, nums: List[int], k: int) -> List[int]:
        pi = [i for i, x in enumerate(nums) if x >= 0]
        px = [x for i, x in enumerate(nums) if x >= 0]
        if len(px):
            d = k % len(px)
            px = px[d:] + px[:d]
        for i in range(len(pi)):
            nums[pi[i]] = px[i]
        return nums

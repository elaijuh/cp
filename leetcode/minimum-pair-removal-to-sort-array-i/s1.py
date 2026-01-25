from typing import List


class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        MAX = 1000 * len(nums)
        ans = 0
        while True:
            s = MAX
            n = len(nums)
            check = True
            for i in range(n - 1):
                if nums[i] > nums[i + 1]:
                    check = False
                if s > nums[i] + nums[i + 1]:
                    s = nums[i] + nums[i + 1]
                    id = i
            if check:
                break
            nums[id] = s
            nums.pop(id + 1)
            ans += 1
        return ans

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        n = len(nums)
        for i in range(n):
            x = target - nums[i]
            if x in num_map:
                return [i, num_map[x]]
            num_map[nums[i]] = i
        return []

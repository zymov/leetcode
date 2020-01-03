from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        l = len(nums)
        if l == 0:
            return 0
        if l == 1:
            return nums[0]
        if l == 2:
            return max(nums[0], nums[1])
        res = [nums[0], max(nums[0], nums[1])]
        for i in range(2, len(nums)):
            tmp = res[i - 2] + nums[i]
            res.append(tmp if tmp > res[i - 1] else res[i - 1])
        return res[l - 1]

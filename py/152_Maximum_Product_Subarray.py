from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        curMin, curMax, finMax = nums[0], nums[0], nums[0]
        for i in nums[1:]:
            if i < 0:
                curMin, curMax = curMax, curMin
            curMin = min(i, curMin * i)
            curMax = max(i, curMax * i)
            finMax = max(finMax, curMax)
        return finMax

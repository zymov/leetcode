"""
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
"""
from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        l = len(nums)
        res = nums[0] + nums[1] + nums[2]
        for i in range(l):
            remain = target - nums[i]
            j, k = i + 1, l - 1
            while j < k:
                twoSum = nums[j] + nums[k]
                if twoSum == remain:
                    return target
                if abs(target - res) > abs(twoSum - remain):
                    res = nums[i] + twoSum
                if twoSum > remain:
                    k -= 1
                else:
                    j += 1
        return res

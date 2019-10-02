"""
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
"""
from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        l = len(nums)
        for i in range(0, l):
            if nums[i] > 0:
                break
            if i > 0 and nums[i - 1] == nums[i]:
                continue
            target = -nums[i]
            j, k = i + 1, l - 1
            while j < k:
                twoSum = nums[j] + nums[k]
                if twoSum < target:
                    j += 1
                elif twoSum > target:
                    k -= 1
                else:
                    res.append((nums[i], nums[j], nums[k]))
                    while j < k and nums[j] == nums[j + 1]:
                        j += 1
                    while j < k and nums[k] == nums[k - 1]:
                        k -= 1
                    j += 1
                    k -= 1
        return res

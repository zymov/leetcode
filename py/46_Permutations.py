"""
Given a collection of distinct integers, return all possible permutations.

Example:
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
"""
from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        self.backtracking(res, nums, [])
        return res

    def backtracking(self, res: List[List[int]], nums: List[int], path: List[int]):
        if not nums:
            res.append(path)
            return
        for i in range(len(nums)):
            self.backtracking(res, nums[:i] + nums[i + 1:], path + [nums[i]])

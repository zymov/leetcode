"""
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
"""
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        self.backtracking(res, nums, [])
        return res

    def backtracking(self, res: List[List[int]], nums: List[int], path: List[int]):
        if not nums:
            res.append(path)
            return
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            self.backtracking(res, nums[:i] + nums[i + 1:], path + [nums[i]])

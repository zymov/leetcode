from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        self.backtracking(nums, res, [], 0)
        return res
    def backtracking(self, nums: List[int], res: List[List[int]], comb: List[int], start: int):
        res.append(comb)
        for i in range(start, len(nums)):
            if i == start or nums[i - 1] != nums[i]:
                self.backtracking(nums, res, comb + [nums[i]], i + 1)

        
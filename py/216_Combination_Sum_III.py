from typing import List

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        nums = [i for i in range(1,10)]
        self.backtracking(nums, 0, k, n, [], res)
        return res

    def backtracking(self, nums: List[int], index: int, k: int, remain: int, comb: List[int], res: List[List[int]]):
        if k < 0 or remain < 0:
            return
        if remain == 0 and k == 0:
            res.append(comb)
        for i in range(index, len(nums)):
            self.backtracking(nums, i + 1, k - 1, remain - nums[i], comb + [nums[i]], res)

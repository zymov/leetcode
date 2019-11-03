from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = [[]]
        for num in nums:
            res += [[num] + r for r in res]
        return res

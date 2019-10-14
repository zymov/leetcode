"""
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
"""
from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        self.backtracking(candidates, res, [], target, 0)
        return res
    
    def backtracking(self, candi: List[int], res: List[List[int]], comb: List[int], remainTarget: int, pos: int):
        if remainTarget == 0:
            res.append(comb)
            return
        for i in range(pos, len(candi)):
            if candi[i] <= remainTarget:
                self.backtracking(candi, res, comb + [candi[i]], remainTarget - candi[i], i)
        

sol = Solution()
print(sol.combinationSum([2,3,5], 8))
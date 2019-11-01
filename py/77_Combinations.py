from typing import List

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        self.backtracking(res, [], n, k, 1)
        return res
    
    def backtracking(self, res: List[List[int]], comb: List[int], n:int, k:int, start:int):
        if len(comb) == k:
            res.append(comb)
            return
        for i in range(start, n + 1):
            self.backtracking(res, comb + [i], n, k, i + 1)


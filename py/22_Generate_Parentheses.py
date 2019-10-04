"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
"""
from typing import List

# TAG: BACKTRACKING
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        self.backtracking(n, 0, '', res)
        return res

    def backtracking(self, openNum: int, closeNum: int, cur: str, res: List):
        if openNum == 0 and closeNum == 0:
            res.append(cur)
            return
        if openNum > 0:
            self.backtracking(openNum - 1, closeNum + 1, cur + '(', res)
        if closeNum > 0:
            self.backtracking(openNum, closeNum - 1, cur + ')', res)
        
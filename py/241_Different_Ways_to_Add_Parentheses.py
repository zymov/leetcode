from typing import List


class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        if input.isdigit():
            return [int(input)]
        res = []
        for i in range(len(input)):
            if input[i] in "+-*":
                res1 = self.diffWaysToCompute(input[:i])
                res2 = self.diffWaysToCompute(input[i+1:])
                for j in res1:
                    for k in res2:
                        res.append(self.helper(input[i], j, k))
        return res

    def helper(self, operator: str, m: int, n: int) -> int:
        if operator == '+':
            return m+n
        elif operator == '-':
            return m-n
        else:
            return m*n

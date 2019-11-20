from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res, n = [], 1
        while n <= numRows:
            if n < 3:
                res.append([1 for i in range(n)])
            else:
                tmp = [1]
                last = res[n - 2]
                for i in range(n - 2):
                    tmp.append(last[i] + last[i + 1])
                tmp.append(1)
                res.append(tmp)
            n += 1
        return res

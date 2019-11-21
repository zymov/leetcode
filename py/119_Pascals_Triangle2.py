class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res, last, n = [], None, 1
        while n <= rowIndex + 1:
            last = res
            if n < 3:
                res = [1 for i in range(n)]
            else:
                res = [1]
                for i in range(n - 2):
                    res.append(last[i] + last[i + 1])
                res.append(1)
            n += 1
        return res

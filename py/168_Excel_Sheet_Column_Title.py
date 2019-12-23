class Solution:
    def convertToTitle(self, n: int) -> str:
        res = []
        while n > 0:
            n, remainder = divmod(n - 1, 26)
            res.append(remainder)
        res.reverse()
        tmp = ''
        for i in res:
            tmp += chr(i + 65)
        return tmp



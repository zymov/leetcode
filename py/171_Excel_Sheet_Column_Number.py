class Solution:
    def titleToNumber(self, s: str) -> int:
        res, d = 0, 1
        for c in s[::-1]:
            res += (ord(c) - 64) * d
            d *= 26
        return res


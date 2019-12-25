class Solution:
    def trailingZeroes(self, n: int) -> int:
        count = 0
        while n > 0:
            k = n // 5
            count += k
            n = k
        return count

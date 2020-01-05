class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        cut = 0
        while m != n:
            m >>= 1
            n >>= 1
            cut += 1
        return m << cut

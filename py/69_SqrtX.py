class Solution:
    def mySqrt(self, x: int) -> int:
        if not x:
            return 0
        low, high, res = 1, x // 2, 1
        while low <= high:
            mid = low + (high - low) // 2
            if mid*mid < x:
                res = mid
                low = mid + 1
            elif mid*mid > x:
                high = mid - 1
            else:
                return mid
        return res
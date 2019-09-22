"""
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers 
within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, 
assume that your function returns 0 when the reversed integer overflows.
"""
class Solution:
    def reverse(self, x: int) -> int:
        sign = (x > 0) - (x < 0)
        n = abs(x)
        res = 0
        while n > 0:
            res = res * 10 + n % 10
            n //= 10
        return res * sign if res < 2**31 else 0

    # use str to int conversion
    def reverse_2(self, x: int) -> int:
        sign = (x > 0) - (x < 0)
        res = int(str(sign * x)[::-1])
        return res * sign * (res < 2**31)

    
sol = Solution()
print(sol.reverse(-31))
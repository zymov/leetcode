"""
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
"""

class Solution:
    def romanToInt(self, s: str) -> int:
        conv = {'M': 1000, 'D': 500, 'C': 100, 'L': 50, 'X': 10, 'V': 5, 'I': 1}
        num, prev = 0, None
        for ch in s:
            value = conv[ch]
            num += value
            if prev and prev < value:
                num -= 2 * prev
            prev = value
        return num

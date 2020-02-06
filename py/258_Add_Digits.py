class Solution:
    def addDigits(self, num: int) -> int:
        while num > 9:
            tmp = 0
            while num > 0:
                num, remain = divmod(num, 10)
                tmp += remain
            num = tmp
        return num

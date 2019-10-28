class Solution:
    def addBinary(self, a: str, b: str) -> str:
        l1, l2 = len(a), len(b)
        length = min(l1, l2)
        res, carry = '', False
        for i in range(1, length + 1):
            tmp = ''
            if a[-i] == '1' and b[-i] == '1':
                tmp = '1' if carry else '0'
                carry = True
            elif a[-i] == '1' or b[-i] == '1':
                tmp = '0' if carry else '1'
                carry = carry and tmp == '0'
            else:
                tmp = '1' if carry else '0'
                carry = False
            res = tmp + res
        c = a if l1 > l2 else b
        for i in range(abs(l1 - l2) - 1, -1, -1):
            if c[i] == '1' and carry:
                res = '0' + res
            else:
                res = ('1' if carry else c[i]) + res
                carry = False
        res = ('1' if carry else '') + res
        return res

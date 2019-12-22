class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        sign = '-' if numerator*denominator < 0 else ''
        n, remain = divmod(abs(numerator), abs(denominator))
        res = [sign + str(n), '.']
        stack = []
        while remain not in stack:
            stack.append(remain)
            n, remain = divmod(remain*10, abs(denominator))
            res.append(str(n))
        idx = stack.index(remain)
        res.insert(idx + 2, '(')
        res.append(')')
        return ''.join(res).replace('(0)', '').rstrip('.')

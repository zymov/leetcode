from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        res, buy = 0, prices[0]
        for p in prices:
            if p - buy > res:
                res = p - buy
            elif p < buy:
                buy = p
        return res

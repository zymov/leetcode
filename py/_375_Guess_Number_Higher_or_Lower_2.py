"""
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.
You end up paying $5 + $7 + $9 = $21.

Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
"""
from typing import List
import sys

class Solution:
    def getMoneyAmount(self, n: int) -> int:
        t = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
        return self.minimax(t, 1, n)

    def minimax(self, table: List[List[int]], start: int, end: int) -> int:
        if start >= end:
            return 0
        if table[start][end]:
            return table[start][end]
        res = sys.maxsize
        for x in range(start, end + 1):
            localMax = x + max(self.minimax(table, start, x - 1), self.minimax(table, x + 1, end))
            res = min(localMax, res)
        table[start][end] = res
        return table[start][end]

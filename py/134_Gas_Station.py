from typing import List

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if not gas:
            return -1
        start, total, remain = 0, 0, 0
        for i in range(len(gas)):
            remain += gas[i] - cost[i]
            total += gas[i] - cost[i]
            if remain < 0:
                start = i + 1
                remain = 0
        return start if total >= 0 else -1

from typing import List

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if len(s) > 12:
            return []
        res = []
        self.backtracking(s, [], res)
        return res
    
    def backtracking(self, remain: str, ipstr: List[str], res: List[str]):
        if len(ipstr) > 0 and (int(ipstr[-1]) > 255 or (ipstr[-1][0] == '0' and len(ipstr[-1]) > 1)):
            return
        if len(remain) == 0 and len(ipstr) == 4:
            res.append('.'.join(ipstr))
            return
        for i in range(1, min(len(remain) + 1, 4)):
            self.backtracking(remain[i:], ipstr + [remain[0:i]], res)
        
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        self.backtracking(s, [], res)
        return res

    def backtracking(self, remain: str, comb: List[str], res: List[List[str]]):
        if not remain:
            res.append(comb)
            return
        for i in range(1, len(remain) + 1):
            tmp = remain[: i]
            if tmp == tmp[::-1]:
                self.backtracking(remain[i:], comb + [remain[:i]], res)

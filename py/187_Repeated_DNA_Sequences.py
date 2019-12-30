from typing import List

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        l, res, dic = len(s), [], {}
        for i in range(l - 9):
            if s[i:i+10] not in dic:
                dic[s[i:i+10]] = 1
            elif dic[s[i:i+10]] == 1:
                res.append(s[i:i+10])
                dic[s[i:i+10]] = 2
        return res

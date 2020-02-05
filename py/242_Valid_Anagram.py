class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic1, dic2 = {}, {}
        for i in s:
            dic1[i] = dic1.get(i, 0) + 1
        for i in t:
            dic2[i] = dic2.get(i, 0) + 1
        return dic1 == dic2

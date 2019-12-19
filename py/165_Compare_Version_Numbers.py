class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1, v2 = version1.split('.'), version2.split('.')
        while v1 or v2:
            v1_val, v2_val = 0, 0
            if v1:
                v1_val = int(v1.pop(0))
            if v2:
                v2_val = int(v2.pop(0))
            if v1_val > v2_val:
                return 1
            if v1_val < v2_val:
                return -1
        return 0

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        slow = len(s) - 1
        while slow >= 0 and s[slow] == ' ':
            slow -= 1
        fast = slow
        while fast >= 0 and s[fast] != ' ':
            fast -= 1
        return slow - fast

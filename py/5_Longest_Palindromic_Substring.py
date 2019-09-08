"""
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
"""

class Solution:
    def longestPalindrome(self, s: str) -> str:
        N = len(s)
        maxLen, start, end = (0,)*3
        if N < 2: return s
        dp = [[False for x in range(N)] for x in range(N)]
        for i in range(N - 1, -1, -1):
            for j in range(i, N):
                dp[i][j] = s[i] == s[j] and (j - i < 2 or dp[i + 1][j - 1])
                if dp[i][j] and (j - i + 1 > maxLen):
                    maxLen = j - i + 1
                    start = i
                    end = j
        return s[start : end + 1]
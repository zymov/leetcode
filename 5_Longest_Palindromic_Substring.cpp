/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"

*/
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
    int lo = 0, maxLen = 1;
    public:
        string longestPalindrome(string s) {
            int len = s.length();
            if(len < 2) return s;
            int start = 0, end = 0, maxLen = 0;
            bool dp[len][len];
            for(int i = len - 1; i >= 0; i--) {
                for(int j = i; j < len; j++) {
                    dp[i][j] = (s[i] == s[j]) && (j - i < 2 || dp[i + 1][j - 1]);
                    if(dp[i][j] && (j - i + 1) > maxLen) {
                        maxLen = j - i + 1;
                        start = i;
                        end = j;
                    }
                }
            }
            return s.substr(start, end - start + 1);
        }

};

int main() {
    Solution sol;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Longest_palindromic_substring
https://www.geeksforgeeks.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/

*/
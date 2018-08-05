/*
Given a string, find the length of the longest substring without repeating characters.

Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<int> M(256, -1);
            int start = -1, len = 0;
            for(int i = 0; i < s.length(); i++) {
                if(M[s[i]] > start) {   // calculate start position using previous repeated character position
                    start = M[s[i]];
                }
                len = max(len, i - start);
                M[s[i]] = i;
            }
            return len;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
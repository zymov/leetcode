/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> patition;
            backtracking(s, res, 0, s.length(), patition);
            return res;
        }

        void backtracking(string s, vector<vector<string>>& res, int pos, int len, vector<string>& partition) {
            if(pos == len) {
                res.push_back(partition);
                return;
            }
            for(int i = pos; i < len; i++) {
                if(isPalindrome(s, pos, i)) {
                    partition.push_back(s.substr(pos, i - pos + 1));
                    backtracking(s, res, i + 1, len, partition);
                    partition.pop_back();
                }
            }
        }

        bool isPalindrome(string s, int start, int end) {
            while(start < end) {
                if(tolower(s[start++]) != tolower(s[end--])) return false;
            }
            return true;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
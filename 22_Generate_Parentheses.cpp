/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        vector<string> generateParenthesis(int n) {
            vector<string> res = {"()"};
            backTracking(res, "", n, 0);
            return res;
        }
        void backTracking(vector<string> &res, string str, int openNum, int closeNum) {
            if(openNum == 0 && closeNum == 0) {
                res.push_back(str);
                return;
            }
            if(openNum > 0)  backTracking(res, str + "(", openNum - 1, closeNum + 1);
            if(closeNum > 0) backTracking(res, str + ")", openNum, closeNum - 1);
        }

};

int main() {
    Solution sol;
    return 0;
}

/*


*/
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> res;
            vector<int> comb;
            backtracking(n, k, res, comb, 1, 0);
            return res;
        }

        void backtracking(int n, int k, vector<vector<int>>& res, vector<int>& comb, int start, int len) {
            if(len == k) {
                res.push_back(comb);
                return;
            }
            for(int i = start; i <= n; i++) {
                comb.push_back(i);
                backtracking(n, k, res, comb, i + 1, len + 1);
                comb.pop_back();
            }
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
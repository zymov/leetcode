/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res;
            res.push_back({});
            vector<int> comb;
            int len = nums.size();
            for(int i = 1; i <= len; i++) {
                backtracking(nums, i, res, comb, 0, 0);
            }
            return res;
        }

        void backtracking(vector<int>& nums, int k, vector<vector<int>>& res, vector<int>& comb, int start, int len) {
            if(len == k) {
                res.push_back(comb);
                return;
            }
            for(int i = start; i < nums.size(); i++) {
                comb.push_back(nums[i]);
                backtracking(nums, k, res, comb, i + 1, len + 1);
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
/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> res = {};
            backtracking(res, {}, candidates, 0, target);
            return res;
        }

        void backtracking(vector<vector<int>>& result, vector<int> combi, vector<int>& candidates, int pos, int remainTarget) {
            if(remainTarget == 0) {
                result.push_back(combi);
                return;
            } else {
                for(int i = pos; i < candidates.size(); i++) {
                    if(remainTarget - candidates[i] >= 0){
                        combi.push_back(candidates[i]);
                        backtracking(result, combi, candidates, i, remainTarget - candidates[i]);
                        combi.pop_back();
                    }
                }
            }
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
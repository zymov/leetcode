/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> res;
            sort(candidates.begin(), candidates.end());
            vector<int> combi;
            backtracking(res, candidates, target, combi, 0);
            return res;
        }

        void backtracking(vector<vector<int>>& result, vector<int>& candidates, int remainTarget, vector<int>& combi, int pos) {
            if(remainTarget == 0) {
                result.push_back(combi);
            }
            int len = candidates.size();
            for(int i = pos; i < len; i++) {
                if(remainTarget - candidates[i] >= 0) {
                    combi.push_back(candidates[i]);
                    backtracking(result, candidates, remainTarget - candidates[i], combi, i + 1);
                    combi.pop_back();
                    while(i + 1 < len && candidates[i + 1] == candidates[i]) i++;
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
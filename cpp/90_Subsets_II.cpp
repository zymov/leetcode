/*
Given a collection of integers that might contain duplicates, nums, 
return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            vector<int> comp;
            backtracking(res, comp, nums, 0);
            return res;
        }
        
        void backtracking(vector<vector<int>>& result, vector<int>& comp, vector<int>& nums, int pos) {
            result.push_back(comp);
            for(int i = pos; i < nums.size(); i++) {
                if(i == pos || nums[i - 1] != nums[i]) {
                    comp.push_back(nums[i]);
                    backtracking(result, comp, nums, i + 1);
                    comp.pop_back();
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
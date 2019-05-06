/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:
All numbers will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> result;
      vector<int> comb;
      backtracking(n, k, result, comb);
      return result;
    }

    void backtracking(int remain, int k, vector<vector<int>>& result, vector<int>& comb) {
      if(remain == 0 && k == 0) {
        result.push_back(comb);
        return;
      }
      if(k <= 0) return;
      for(int i = comb.empty() ? 1 : comb.back() + 1; i <= 9; i++) {
        if(remain - i < 0) break;
        comb.push_back(i);
        backtracking(remain - i, k - 1, result, comb);
        comb.pop_back();
      }
    }
};

int main() {
  return 0;
}

/*


*/
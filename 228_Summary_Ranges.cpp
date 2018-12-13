/*
Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:
Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.

Example 2:
Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {
      int len = nums.size();
      vector<string> res;
      for(int i = 0; i < len; i++) {
        string tmp = to_string(nums[i]);
        int start = i;
        while(nums[i + 1] - nums[i] == 1) i++;
        res.push_back(i == start ? tmp : (tmp + "->" + to_string(nums[i])));
      }
      return res;
    }
};

int main() {
  return 0;
}

/*


*/
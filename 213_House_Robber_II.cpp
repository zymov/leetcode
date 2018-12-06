/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.

Example 2:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      if(n < 2) return n ? nums[0] : 0;
      return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }

    int robber(vector<int>& nums, int start, int end) {
      int temp, pre = 0, s = 0;
      for(int i = start; i <= end; i++) {
        temp = s;
        if(pre + nums[i] > s)
          s = pre + nums[i];
        pre = temp;
      }
      return s;
    }
};

int main() {
  return 0;
}

/*


*/
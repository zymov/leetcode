/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:
Input: [3,2,3]
Output: [3]

Example 2:
Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
      int countA = 0, countB = 0, len = nums.size();
      int majorA, majorB;
      vector<int> res;
      for(int i = 0; i < len; i++) {
        if(majorA == nums[i]) {
          countA++;
        } else if (majorB == nums[i]) {
          countB++;
        } else if(countA == 0) {
          majorA = nums[i];
          countA = 1;
        } else if(countB == 0) {
          majorB = nums[i];
          countB = 1;
        } else {
          countA--;
          countB--;
        }
      }
      countA = countB = 0;
      for(int n : nums) {
        if(n == majorA) countA++;
        if(n == majorB) countB++;
      }
      if(countA > len / 3) res.push_back(majorA);
      if(countB > len / 3) res.push_back(majorB);
      return res;
    }
};

int main() {
  return 0;
}

/*
hint: How many majority elements could it possibly have?

*/
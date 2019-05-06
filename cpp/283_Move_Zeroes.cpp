/*
Given an array nums, write a function to move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        void moveZeroes(vector<int>& nums) {
            int movestep = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) {
                    movestep++;
                } else if(movestep) {
                    nums[i - movestep] = nums[i];
                    nums[i] = 0;
                }
            }
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*
Similar question: No.27 Remove Element

*/
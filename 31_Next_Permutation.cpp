/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        void nextPermutation(vector<int>& nums) {
            int len = nums.size(), swapA = len - 2, swapB = len - 1;
            for(; swapA >= 0; swapA--) {
                if(nums[swapA] < nums[swapA + 1]) break;
            }
            if(swapA < 0) {
                reverse(nums.begin(), nums.end());
            } else {
                for(; swapB > swapA; swapB--) {
                    if(nums[swapA] < nums[swapB]) break;
                }
                swap(nums[swapA], nums[swapB]);
                reverse(nums.begin() + swapA + 1, nums.end());
            }
        }
};

int main() {
    Solution sol;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order

*/
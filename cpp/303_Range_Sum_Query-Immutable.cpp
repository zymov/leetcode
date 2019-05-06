/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/
#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    private:
        vector<int> n, s;
    public:
        NumArray(vector<int> nums) {
            n = nums;
            s.push_back(0);
            for(int k = 0; k < n.size(); k++) {
                s.push_back(s.back() + n[k]);
            }
        }
        
        int sumRange(int i, int j) {
            return s[j + 1] - s[i];
        }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */


int main() {
    return 0;
}

/*


*/
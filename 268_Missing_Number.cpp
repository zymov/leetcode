/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
find the one that is missing from the array.

Example 1:
Input: [3,0,1]
Output: 2

Example 2:
Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. 
Could you implement it using only constant extra space complexity?


*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int missingNumber(vector<int>& nums) {
            int l = nums.size();
            int s = (l + 1)*l / 2;
            for(int i = 0; i < l; i++) {
                s -= nums[i];
            }
            return s;
        }

        int missingNumber_Same(vector<int>& nums) {
            int sum = nums.size();
            for(int i = 0; i < nums.size(); i++) {
                sum += i - nums[i];
            }
            return sum;
        }

        int missingNumber_Bit(vector<int>& nums) {
            int bitXOR = 0, i = 0;
            for(; i < nums.size(); i++) {
                bitXOR ^= i ^ nums[i];
            }
            return bitXOR ^ i;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        vector<int> plusOne(vector<int>& digits) {
            int idx = digits.size() - 1;
            digits[idx] += 1;
            while(digits[idx] > 9) {
                digits[idx] = 0;
                if(idx == 0) {
                    digits.insert(digits.begin(), 1);
                } else {
                    digits[--idx] += 1;
                }
            }
            return digits;
        }
        
};

int main() {
    Solution sol;
    vector<int> aa = {9};
    sol.plusOne(aa);
    return 0;
}
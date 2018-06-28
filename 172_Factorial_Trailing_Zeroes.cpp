/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:
Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.

Note: Your solution should be in logarithmic time complexity.
*/
#include <iostream>
#include <cmath>

using namespace std;

class Solution {

    public:
        int trailingZeroes(int n) {
            int count = 0;
            int k = 0;
            while(n > 0) {
                k = n / 5;
                count += k;
                n = k;
            }
            return count;
        }
};

int main() {
    Solution sol;
    cout << sol.trailingZeroes(625) << endl;
    return 0;
}

/*


*/
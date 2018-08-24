/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
Return the quotient after dividing dividend by divisor.
The integer division should truncate toward zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

Example 2:
Input: dividend = 7, divisor = -3
Output: -2

Note:
Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer 
range: [−231,  231 − 1]. For the purpose of this problem, 
assume that your function returns 231 − 1 when the division result overflows.
*/
#include <iostream>

using namespace std;

class Solution {
    
    public:
        int divide(int dividend, int divisor) {
            if (dividend == INT_MIN && divisor == -1) return INT_MAX;
            bool minus = false;
            if((dividend < 0) ^ (divisor < 0)) minus = true;
            long long d1 = labs(dividend),
                d2 = labs(divisor),
                res = 0;
            while(d1 >= d2) {
                long long factor = 1, temp = d2;
                while(d1 >= (temp << 1)) {
                    temp <<= 1;
                    factor <<= 1;
                }
                d1 -= temp;
                res += factor;
            }
            return minus ? -res : res;
        }
};

int main() {
    Solution sol;
    cout << sol.divide(2147483647, 3) << endl;
    return 0;
}

/*


*/
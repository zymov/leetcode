/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:
Input: 2.00000, 10
Output: 1024.00000

Example 2:
Input: 2.10000, 3
Output: 9.26100

Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:
-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
#include <iostream>

using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            if(n == 0 || x == 1) return 1;
            if(x == -1) {
                if(n % 2 == 0) return -x;
                return x;
            }
            if(n == INT_MIN) return 0;
            if(n < 0) {
                n = -n;
                x = 1 / x;
            }
            if(n % 2 == 0) {
                return myPow(x*x, n / 2);
            } else {
                return x * myPow(x*x, n / 2);
            }

        }

        double myPow_Bit(double x, int n) {
            bool flag = true;
            long long nn = n;
            if(n < 0) {
                flag = false;
                nn = -nn;
            }
            double res = 1.0;
            double base = x;
            while(nn) {
                if(nn & 1) {
                    res *= base;
                }
                base *= base;
                nn >>= 1;
            }
            return flag ? res : 1 / res;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
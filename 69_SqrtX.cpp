/*
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:
Input: 4
Output: 2

Example 2:
Input: 8
Output: 2

Explanation: 
The square root of 8 is 2.82842..., and since 
the decimal part is truncated, 2 is returned.
*/
#include <iostream>

using namespace std;

class Solution {

    public:
        int mySqrt(int x) {
            if(x == 0) return 0;
            int lo = 1, hi = x;
            int mid, res;
            while(lo <= hi) {
                mid = lo + (hi - lo) / 2;
                if(mid <= x / mid) {
                    res = mid;                        
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                } 
            }
            return res;
        }

        
};

int main() {
    Solution sol;
    cout << sol.mySqrt(5) << endl;
    return 0;
}
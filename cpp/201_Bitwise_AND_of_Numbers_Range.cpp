/*
Given a range [m, n] where 0 <= m <= n <= 483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/
#include <iostream>

using namespace std;

class Solution {
    public:
        int rangeBitwiseAnd(int m, int n) {
            int cut = 0;
            while(m != n) {
                m >>= 1;
                n >>= 1;
                cut++;
            }
            return m << cut;
        }
};

int main() {
    return 0;
}

/*
if m != n, there has at least one odd and one even number, so the last position is always 0.
so cut off difference bit number by move right one bit.

*/
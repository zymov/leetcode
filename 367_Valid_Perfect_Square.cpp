/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:
Input: 16
Returns: True

Example 2:
Input: 14
Returns: False
*/
#include <iostream>

using namespace std;

class Solution {

    public:
        bool isPerfectSquare(int num) {
            int low = 1, high = num / 2; 
            while(low < high) {
                long long mid = low + (high - low) / 2;
                if(mid*mid > num) {
                    high = mid - 1;
                } else if(mid*mid < num) {
                    low = mid + 1;
                } else {
                    return true;
                }
            }
            return low*low == num;
        }
        
        // perfect square number is 1 + 3 + 5 + 7 + ....
        bool isPerfectSquare_Simple(int num) {
            int i = 1;
            while(num > 0) {
                num -= i;
                i += 2;
            }
            return num == 0;
        }

        bool isPerfectSquare_Newton_Method(int num) {
            int i = num;
            while(i*i > num) {
                i = (i + num/i) >> 1;
            }
            return i*i == num;
        }
};

int main() {
    Solution sol;
    cout << sol.isPerfectSquare_Newton_Method(64) << endl;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Integer_square_root

*/
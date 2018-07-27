/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/
#include <iostream>

using namespace std;

class Solution {
    
    public:
        bool isPowerOfFour(int n) {
            if(n <= 0) return false;
            while(n % 4 == 0) {
                n /= 4;
            }
            return n == 1;
        }
        
        bool isPowerOfFour_Bit(int n) {
            return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
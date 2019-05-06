/*
Given an integer, write a function to determine if it is a power of two.

Example 1:
Input: 1
Output: true 
Explanation: 20 = 1

Example 2:
Input: 16
Output: true
Explanation: 24 = 16

Example 3:
Input: 218
Output: false
*/
#include <iostream>

using namespace std;

class Solution {
    
    public:
        bool isPowerOfTwo(int n) {
            if(n <= 0) return false;
            int r;
            while(n > 2) {
                r = n % 2;
                if(r == 1) return false;
                n = n / 2;
            }
            return true;
        }
        
        bool isPowerOfTwo_Better(int n) {
            if(n <= 0) return false;
            return !(n&(n-1));
        }
};

int main() {
    Solution sol;
    cout << sol.isPowerOfTwo_Better(8) << endl;
    return 0;
}

/*


*/
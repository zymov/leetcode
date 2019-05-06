/*
Given an integer, write a function to determine if it is a power of three.
*/
#include <iostream>

using namespace std;

class Solution {
    
    public:
        bool isPowerOfThree(int n) {
            if(n <= 0) return false;
            while(n % 3 == 0) {
                n /= 3;
            }
            return n == 1;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
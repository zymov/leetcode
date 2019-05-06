/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:
Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/
#include <iostream>

using namespace std;

class Solution {
    
    public:
        int addDigits(int num) {
            if(num < 10) return num;
            int s = 0;
            while(num > 0) {
                s += num % 10;
                num = num / 10;
            }
            if(s > 9) addDigits(s);
            else return s;
        }

        int addDigits_Math(int num) {
            return 1 + (num - 1) % 9;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Digital_root

*/
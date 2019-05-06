/*
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: 
Starting with any positive integer, 
replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Example: 
Input: 19
Output: true

Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
#include <iostream>
#include <cmath>

using namespace std;

class Solution {

    public:
        bool isHappy(int n) {
            int s = 0;
            while(n > 0) {
                s += pow(n % 10, 2);
                n /= 10;
            }
            if(s == 1) return true;
            if(s == 4) return false;
            return isHappy(s);
        }

        bool isHappy_Better(int n) {
            int slow = n, fast = n;
            do {
                slow = getSum(slow);
                fast = getSum(getSum(fast));
            } while (slow != fast);
            return slow == 1;
        }
        
        int getSum(int n) {
            int s = 0;
            while(n > 0) {
                s += pow(n % 10, 2);
                n /= 10;
            }
            return s;
        }
        
};

int main() {
    Solution sol;
    cout << sol.isHappy(9) << endl;
    cout << sol.isHappy_Better(19) << endl;
    return 0;
}

/*
use the algorithm for detecting cycle in linked list
similar question : 141

*/
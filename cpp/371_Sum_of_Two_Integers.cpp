/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
*/
#include <iostream>

using namespace std;

class Solution {
    
    public:
        int getSum(int a, int b) {
            while(b != 0) {
                int carry = a & b;
                a = a ^ b;
                b = carry << 1;
            }
            return a;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Adder_%28electronics%29#Half_adder
https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary:-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
*/
/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:
Input: 11
Output: 3
Explanation: Integer 11 has binary representation 00000000000000000000000000001011 

Example 2:
Input: 128
Output: 1
Explanation: Integer 128 has binary representation 00000000000000000000000010000000
*/
#include <iostream>

using namespace std;

class Solution {
    
    public:
        int hammingWeight(uint32_t n) {
            int count = 0;
            while(n > 0) {
                n &= n - 1;
                count++;
            }
            return count;
        }

        int hammingWeight_2(uint32_t n) {
            string zBit = bitset<64>(n).to_string();
            return count(zBit.begin(), zBit.end(), '1');
        }
};

int main() {
    Solution sol;
    cout << sol.hammingWeight(1431655765) << endl;
    cout << sol.hammingWeight(4294967295) << endl;
    return 0;
}

/*


*/
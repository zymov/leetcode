/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, 
print the sequence of gray code. A gray code sequence must begin with 0.

Example 1:
Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1

Example 2:
Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
             Therefore, for n = 0 the gray code sequence is [0].
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> res;
            bitset<32> bits;
            backtracking(bits, res, n);
            return res;
        }

        void backtracking(bitset<32>& bits, vector<int>& result, int l) {
            if(l == 0) {
                result.push_back(bits.to_ulong());
            } else {
                backtracking(bits, result, l - 1);
                bits.flip(l - 1);
                backtracking(bits, result, l - 1);
            }
        }
};

int main() {
    Solution sol;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Gray_code

*/
/*
Reverse bits of a given 32 bits unsigned integer.

Example:
Input: 43261596
Output: 964176192
Explanation: 
43261596 
represented in binary as 00000010100101000001111010011100, 
return 964176192 
represented in binary as 00111001011110000010100101000000.

Follow up:
If this function is called many times, how would you optimize it?
*/
#include <iostream>

using namespace std;

class Solution {
    
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t res = 0;
            for (int i = 0; i < 32; i++) {
                res <<= 1;
                res += n & 1;
                n >>= 1;
            }
            return res;
        }

        uint32_t reverseBits_From_Book(uint32_t x) {
           x = (x & 0x55555555) <<  1 | (x & 0xAAAAAAAA) >>  1;
           x = (x & 0x33333333) <<  2 | (x & 0xCCCCCCCC) >>  2;
           x = (x & 0x0F0F0F0F) <<  4 | (x & 0xF0F0F0F0) >>  4;
           x = (x & 0x00FF00FF) <<  8 | (x & 0xFF00FF00) >>  8;
           x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;
           return x;
        }


        // helper functions
        string toBinary(uint32_t n) {
            string s = "";
            while(n > 0) {
                s = to_string(n % 2) + s;
                n = n / 2;
            }
            return s;
        }

        uint32_t toInt(string s) {
            uint32_t n = 0;
            int base = 1;
            int l = s.length();
            for(int i = l - 1; i >= 0; i--) {
                n += (s[i] - '0') * base;
                base *= 2;
            }
            return n;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*
http://www.hackersdelight.org/hdcodetxt/reverse.c.txt

*/
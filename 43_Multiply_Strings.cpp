/*
Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        string multiply(string num1, string num2) {
            string res(num1.length() + num2.length(), '0');
            for(int i = num1.length() - 1; i >= 0; i--) {
                int carry = 0;
                for(int j = num2.length() - 1; j >= 0; j--) {
                    int temp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                    res[i + j + 1] = temp % 10 + '0';
                    carry = temp / 10;
                }
                res[i] += carry;
            }
            int firstNotZero = res.find_first_not_of('0');
            if(string::npos != firstNotZero) return res.substr(firstNotZero);
            return "0";
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
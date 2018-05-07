/*
g++ -std=c++11 
*/
#include <iostream>

using namespace std;

class Solution {

    public:
        string addBinary(string a, string b) {
            int alen = a.length();
            int blen = b.length();
            int len = max(alen, blen);
            int i, j, carry = 0;
            string result;

            if(alen < blen) {
                for(j = 0; j < blen - alen; j++) {
                    a = '0' + a;
                }
            } else if(alen > blen) {
                for(j = 0; j < alen - blen; j++) {
                    b = '0' + b;
                }
            }

            for(i = len - 1; i >= 0; i--) {
                int ia = a[i] - '0';
                int ib = b[i] - '0';
                char sum = (ia ^ ib ^ carry) + '0';
                result = sum + result;
                carry = ia + ib + carry > 1 ? 1 : 0;
            }

            if(carry) {
                result = '1' + result;
            }
            
            return result;

        }
        
};

int main() {
    Solution sol;

    string str1 = "1100011";
    string str2 = "101";
 
    cout << "Sum is " << sol.addBinary(str1, str2) << endl;
    return 0;
}
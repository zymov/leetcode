/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

Example 1:
Input: 1
Output: "A"

Example 2:
Input: 28
Output: "AB"

Example 3:
Input: 701
Output: "ZY"
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        string convertToTitle(int n) {
            string res = "";
            while(n > 0) {
                int remain = n % 26;
                n = n / 26;
                if(remain == 0) {
                    n = n - 1;
                    remain = 26;
                }
                res = char(remain + 64) + res;
                 
            }
            return res;
        }

        string convertToTitle_Better(int n) {
            string s = "";
            char temp;

            while(n > 0) {
                n -= 1;
                temp = 'A' + n % 26;
                s = temp + s;
                n /= 26;
            }
            return s;
        }
};

int main() {
    Solution sol;
    cout << sol.convertToTitle(28) << endl;
    // cout << char(90) << endl;
    return 0;
}

/*


*/
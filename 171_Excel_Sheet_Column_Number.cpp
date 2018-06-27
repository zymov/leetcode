/*
Given a column title as appear in an Excel sheet, 
return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

Example 1:
Input: "A"
Output: 1

Example 2:
Input: "AB"
Output: 28

Example 3:
Input: "ZY"
Output: 701
*/
#include <iostream>
#include <cmath>

using namespace std;

class Solution {

    public:
        int titleToNumber(string s) {
            int n = s.length();
            int res = 0;
            for(int i = 0; i < n; i++) {
                res += pow(26, n - i - 1) * (s[i] - 'A' + 1);
            }
            return res;
        }

        int titleToNumber_Better(string s) {
            int num = 0;
            for (char c : s) {
                num += num * 25 + (c - 'A' + 1);
            }
            return num;
        }
};

int main() {
    Solution sol;
    cout << sol.titleToNumber("A") << endl;
    cout << sol.titleToNumber_Better("BB") << endl;
    cout << sol.titleToNumber_Better("ZY") << endl;

    return 0;
}

/*


*/
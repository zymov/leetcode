/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:
Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int res = 0;
        int numDecodings(string s) {
            dp(s);
            return res;
        }
        // recursive dp solution will cause time limitation
        void dp(string rest) {
            if(rest.size() == 0) {
                res++;
                return;
            }
            if(rest[0] != '0') dp(rest.substr(1));
            if(rest.size() > 1 && (rest[0] == '1' || (rest[0] == '2' && rest[1] < '7'))) {
                dp(rest.substr(2));
            }
        }

        // iterative dp solution
        int numDecodings_DP_Iter(string s) {
            if(s == "0") return 0;
            vector<int> results(s.size() + 1, 0);
            int i = s.size();
            results[i] = 1;
            results[i - 1] = s[i - 1] == '0' ? 0 : 1;
            for(i = i - 2; i >= 0; i--) {   // from end to start
                if(s[i] == '0') continue;
                if((s[i] == '2' && s[i + 1] < '7') || s[i] == '1') {
                    results[i] = results[i + 1] + results[i + 2];
                } else {
                    results[i] = results[i + 1];
                }
            }
            return results[0];
        }

};

int main() {
    Solution sol;
    return 0;
}

/*


*/
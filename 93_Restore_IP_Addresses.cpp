/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            if(s.size() > 12) return {};
            vector<string> res;
            string comp = "";
            backtracking(res, s, comp, 0, 0);
            return res;
        }

        void backtracking(vector<string> &res, string s, string comp, int index, int count) {
            if(count > 4) return;
            if(index == s.size() && count == 4) {
                res.push_back(comp);
            }
            for(int i = 1; i < 4; i++) {
                if(index + i > s.size()) break;
                string t = s.substr(index, i);
                if((t[0] == '0' && t.size() > 1) || stoi(t) > 255) continue;
                backtracking(res, s, comp + t + (count == 3 ? "" : "."), index + i, count + 1);
            }
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Solution {

    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() == 0 || strs[0] == "") {
                return "";
            }
            string firstStr = strs[0];
            char ch = firstStr[0];
            int idx = 0;

            for(int i = 0; i < strs[0].size(); i++) {
                ch = firstStr[i];
                for(int j = 0; j < strs.size(); j++) {
                    if(ch != strs[j][i]) {
                        return firstStr.substr(0, i);
                    }
                }
                idx = i;
            }

            return firstStr.substr(0, idx + 1);
        }
    
};

int main() {
    Solution sol;
    vector<string> strs = {"a", "ab"};
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}






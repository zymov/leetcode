/*
Given a string, find the first non-repeating character in it and return it's index. 
If it doesn't exist, return -1.

Examples:
s = "leetcode"
return 0.
s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
        int firstUniqChar(string s) {
            unordered_map<char, int> map;
            int l = s.length();
            for(int i = 0; i < l; i++) {
                ++map[s[i]];
            }
            for(int i = 0; i < l; i++) {
                if(map[s[i]] == 1) return i;
            }
            return -1;
        }

        int firstUniqChar_Better(string s) {
            vector<int> m(26, 0);
            for(int i = 0; i < s.length(); i++) {
                m[s[i] - 'a']++;
            }
            for(int i = 0; i < s.length(); i++) {
                if(m[s[i] - 'a'] == 1) return i;
            }
            return -1;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
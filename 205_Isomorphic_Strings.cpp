/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character 
while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Note:
You may assume both s and t have the same length.
*/
#include <iostream>

using namespace std;

class Solution {

    public:
        bool isIsomorphic(string s, string t) {
            int len = s.size();
            int mapS[256] = {0};
            int mapT[256] = {0};

            for(int i = 0; i < len; i++) {
                if(mapS[s[i]] != mapT[t[i]]) return false;
                mapS[s[i]] = i + 1;
                mapT[t[i]] = i + 1;
            }

            return true;
        }
};

int main() {
    Solution sol;
    string s = "aba", t = "baa";
    cout << sol.isIsomorphic(s,t) << endl;
    return 0;
}

/*


*/
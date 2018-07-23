/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, 
such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:
Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:
Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:
Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, 
and str contains lowercase letters separated by a single space.
*/
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {

    public:
        bool wordPattern(string pattern, string str) {
            unordered_map<char, string> pMap;
            unordered_map<string, char> sMap;
            istringstream iss(str);
            string word;
            int i = 0;
            for(; iss >> word; i++) {
                if(pMap.find(pattern[i]) == pMap.end() && sMap.find(word) == sMap.end()) {
                    pMap[pattern[i]] = word;
                    sMap[word] = pattern[i];
                } else if(pMap[pattern[i]] != word || sMap[word] != pattern[i]) {
                    return false;
                }
            }
            return i == pattern.size();
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
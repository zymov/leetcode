/*
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> res;
            unordered_map<string, int> map;
            int len = strs.size(), begin = 0;
            string temp = "";
            for(int i = 0; i < len; i++){
                string ss = strs[i];
                temp = ss;
                sort(ss.begin(), ss.end());
                if(map.find(ss) != map.end()) {
                    res[map[ss]].push_back(temp);
                } else {
                    res.push_back({temp});
                    map[ss] = begin++;
                }
            }
            return res;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
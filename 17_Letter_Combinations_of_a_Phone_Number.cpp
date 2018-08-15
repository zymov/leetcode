/*
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            if(digits.length() == 0) return {};
            vector<string> res = {""};
            vector<string> m = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            int numbers = stoi(digits);
            while(numbers > 0) {
                int idx = numbers % 10 - 2;
                numbers /= 10;
                int len = m[idx].size();
                int prevStrArrLen = res.size();
                vector<string> newRes;
                for(int i = 0; i < len; i++) {
                    for(int j = 0; j < prevStrArrLen; j++) {
                        newRes.push_back(m[idx][i] + res[j]);
                    }
                }
                res = newRes;
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
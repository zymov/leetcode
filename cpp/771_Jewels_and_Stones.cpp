/*
You're given strings J representing the types of stones that are jewels,
and S representing the stones you have.
Each character in S is a type of stone you have.
You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct,
and all characters in J and S are letters.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:

Input: J = "z", S = "ZZ"
Output: 0

Note:
S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/

#include <iostream>
#include <set>
using namespace std;

class Solution {
    int jewelNum = 0;
public:
    int numJewelsInStones(string J, string S) {
        for (int i = 0; i < S.length(); i++) {
            for(int j = 0; j < J.length(); j++) {
                if(J[j] == S[i]) {
                    jewelNum++;
                    break;
                } 
            }
        }
        return jewelNum;
    }

    // hash map 
    int notMySolution(string J, string S) {
        int res = 0;
        set<char>setJ(J.begin(), J.end());
        for(char s : S) {
            if(setJ.count(s)) {
                res++;
            }
        }
        return res;
    }

};

int main() {
    Solution sol;
    int result = sol.numJewelsInStones("aA", "aAAbabbb");
    cout << result << endl;
}






















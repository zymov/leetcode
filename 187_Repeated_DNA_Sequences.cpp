/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            int len = s.size();
            if(len <= 10) return {};
            vector<string> res;
            set<int> once;
            set<int> twice;
            for(int i = 0; i < len - 9; i++) {
                int val = 0;
                for(int j = i; j < i + 10; j++) {
                    val <<= 2;
                    val |= char2Int(s[j]);
                }
                if(!once.count(val)) {
                    once.insert(val);
                } else if(once.count(val) && !twice.count(val)) {
                    twice.insert(val);
                    res.push_back(s.substr(i, 10));
                }
            }
            return res;
        }

        int char2Int(char c) {
            switch(c) {
                case 'A': return 0;
                case 'C': return 1;
                case 'G': return 2;
                case 'T': return 3;
            }
        }
};

int main() {
    return 0;
}

/*
https://leetcode.com/problems/repeated-dna-sequences/discuss/53952/20-ms-solution-(C++)-with-explanation

*/
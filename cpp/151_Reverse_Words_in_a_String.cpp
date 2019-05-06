/*
Given an input string, reverse the string word by word.

Example:  
Input: "the sky is blue",
Output: "blue is sky the".

Note:
A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, 
your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.

Follow up: For C programmers, try to solve it in-place in O(1) space.
*/
#include <iostream>

using namespace std;

class Solution {
    public:
        void reverseWords(string &s) {
            reverse(s.begin(), s.end());
            int len = s.size();
            int lastIndex = 0;  // no space index
            for(int i = 0; i <len; i++) {
                if(s[i] != ' ') {
                    if(lastIndex) s[lastIndex++] = ' ';
                    int j = i;
                    while(j < len && s[j] != ' ') s[lastIndex++] = s[j++];
                    reverse(s.begin() + lastIndex - (j - i), s.begin() + lastIndex);
                    i = j;
                }
            }
            s.erase(s.begin() + lastIndex, s.end());
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:
Input: "race a car"
Output: false

*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
    
    public:
        bool isPalindrome(string s) {
            for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
                while(!isalnum(s[i]) && i < j) i++;
                while(!isalnum(s[j]) && i < j) j--;
                if(tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
            }
            return true;
        }
};

int main() {
    Solution sol;
    sol.isPalindrome("A man, a plan, a canal: Panama");
    sol.isPalindrome("A man, a plan, a canal: Panama");
    return 0;
}
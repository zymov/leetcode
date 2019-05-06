/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/
#include <iostream>

using namespace std;

class Solution {
    
    public:
        string reverseVowels(string s) {
            char t;
            char vowels[] = "aeiouAEIOU";
            int low = 0, high = s.length() - 1;
            while(low < high) {
                while(strchr(vowels, s[low]) == NULL) { ++low; }
                while(strchr(vowels, s[high]) == NULL) { --high; }
                if(low < high) {
                    t = s[low];
                    s[low] = s[high];
                    s[high] = t;
                    low++;
                    high--;
                }
            }
            return s;
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
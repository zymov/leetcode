/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/
#include <iostream>

using namespace std;

class Solution {
    
    public:
        string reverseString(string s) {
            char t;
            int l = s.length(), low = 0, high = l - 1;
            while(low < high) {
                t = s[low];
                s[low] = s[high];
                s[high] = t;
                low++;
                high--;
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
/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:
Input: [10,2]
Output: "210"

Example 2:
Input: [3,30,34,5,9]
Output: "9534330"

Note: The result may be very large, so you need to return a string instead of an integer.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string largestNumber(vector<int>& nums) {
            if(all_of(nums.begin(), nums.end(), [](int num) { return num == 0; })) return "0";
            vector<string> numStrs;
            string res;
            for(auto n : nums) {
                numStrs.push_back(to_string(n));
            }
            sort(numStrs.begin(), numStrs.end(), [](string s1, string s2){ return s1 + s2 > s2 + s1;});
            for(auto s : numStrs) {
                res += s;
            }
            return res;
        }
};

int main() {
    return 0;
}

/*


*/
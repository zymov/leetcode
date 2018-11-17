/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            if(numerator == 0) return "0";
            string res;
            if(numerator < 0 ^ denominator < 0) res = "-";
            long n = numerator < 0 ? -(long)numerator : (long)numerator;
            long d = denominator < 0 ? -(long)denominator : (long)denominator;
            res += to_string(n / d);
            long rmd = n % d;
            if(rmd == 0) return res;
            res += ".";
            rmd *= 10;
            unordered_map<long, long> map;
            while(rmd) {
                long frac = rmd / d;
                if(map.count(rmd)) {
                    res.insert(map[rmd], 1, '(');
                    res += ')';
                    return res;
                }
                map[rmd] = res.size();
                res += to_string(frac);
                rmd = (rmd % d) * 10;
            }
            return res;
        }
};

int main() {
    Solution sol;
    cout << (float)2 / 1 << endl;
    return 0;
}

/*


*/
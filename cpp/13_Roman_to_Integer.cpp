/*
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <vector>

using namespace std;

string symbol = "IVXLCDM";
vector<int> symbolValue = {1, 5, 10, 50, 100, 500, 1000};

class Solution {

    public:
        int romanToInt(string s) {
            int sum = 0;
            int prevIdx = -1;
            for(int i = 0; i < s.length(); i++) {
                int curInx = symbol.find(s[i], 0);
                if(prevIdx != -1 && prevIdx < curInx) {
                    sum -= 2 * symbolValue[prevIdx];
                }
                sum += symbolValue[curInx];
                prevIdx = curInx;
            }
            return sum;
        }
    
};

int main() {
    Solution sol;
    cout << to_string(sol.romanToInt("DCCC") == 800) << endl;
    cout << to_string(sol.romanToInt("XCIX") == 99) << endl;
    cout << to_string(sol.romanToInt("LXXXIX") == 89) << endl;
    cout << to_string(sol.romanToInt("LXXIV") == 74) << endl;
    return 0;
}








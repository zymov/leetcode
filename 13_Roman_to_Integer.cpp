

#include <iostream>
#include <vector>
#include <unordered_map>

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
    cout << sol.romanToInt("DCCC") << " == 800" << endl;
    cout << sol.romanToInt("XCIX") << " == 99" << endl;
    cout << sol.romanToInt("LXXXIX") << " == 89" << endl;
    cout << sol.romanToInt("LXXIV") << " == 74" << endl;
    return 0;
}








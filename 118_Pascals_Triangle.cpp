/*
Given a non-negative integer numRows, 
generate the first numRows of Pascal's triangle.

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        vector<vector<int>> generate(int numRows) {
            if(numRows == 0) return {};
            vector<vector<int>> l;
            vector<int> last = {1};
            l.push_back(last);
            int n = 2;
            while(n <= numRows) {
                int i = 0;
                vector<int> pas = {1};
                for(i = 0; i < n - 2; i++) {
                    pas.push_back(last[i] + last[i+1]);
                }
                pas.push_back({1});
                l.push_back(pas);
                last = pas;
                n++;
            }
            return l;

        }
        
};

int main() {
    Solution sol;
    return 0;
}
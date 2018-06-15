/*
Given a non-negative index k where k ≤ 33, 
return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:
Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        vector<int> getRow(int rowIndex) {  //rowIndex start from 0
            if(rowIndex == 0) return {1};
            vector<int> last = {1};
            int n = 1;
            vector<int> pas = {1};
            while(n <= rowIndex) {
                for(int i = 0; i < n - 1; i++) {
                    pas.push_back(last[i] + last[i+1]);
                }
                pas.push_back({1});
                last = pas;
                pas = {1};
                n++;
            }
            return last;
        }

        // other solution
        vector<int> otherSolution(int rowIndex) {
            vector<int> A(rowIndex+1, 0);
            A[0] = 1;
            for(int i = 1; i < rowIndex + 1; i++) {
                for(int j = i; j >= 1; j--) {
                    A[j] += A[j - 1];
                }
            }
            return A;
        }
        
};

int main() {
    Solution sol;
    return 0;
}
/*
The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"
*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
    public:
        string getPermutation(int n, int k) {
            vector<int> Factorials = {1};
            for(int i = 1; i <= n; i++) {
                Factorials.push_back(Factorials[i - 1] * i);
            }
            string res;
            vector<char> numb{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
            k--;
            while(n > 0) {
                int pos = k / Factorials[n - 1];
                res += numb[pos];
                numb.erase(numb.begin() + pos);
                k -= pos * Factorials[n - 1];
                n--;
            }
            return res;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
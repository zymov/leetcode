/*
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
    public:
        int countPrimes(int n) {
            if(n < 3) return 0;
            int count = 1; 
            vector<bool> isNotPrime(n, false);
            for(int i = 3; i < n; i+=2) {
                if(!isNotPrime[i]) {
                    count++;
                    for(int j = 2; i * j < n; j++) {
                        isNotPrime[i * j] = true;
                    }
                }
            }
            return count;
        }
};

int main() {
    Solution sol;
    cout << sol.countPrimes(10) << endl;
    return 0;
}

/*
https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

*/
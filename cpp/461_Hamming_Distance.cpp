/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.

Example:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ^   ^
The above arrows point to positions where the corresponding bits are different.

reference:
https://en.wikipedia.org/wiki/Hamming_distance

*/

#include <iostream>
#include <list>
#include <bitset>

using namespace std;

class Solution {
    public:
        int hammingDistance(int x, int y) {
            int z = x ^ y;
            string zBit = bitset<64>(z).to_string();
            return count(zBit.begin(), zBit.end(), '1');
        };


        /**
            n &= n - 1 converts the right most 1 to 0.
            This is the key idea solving the problem. 
            By counting how many times we can perform this operation, 
            we know how many 1 exists in the binary representation of n
        */
        int NOT_MY_SOLUTION(int x, int y) {
            int dist = 0, n = x ^ y;
            while(n) {
                ++dist;
                n &= n - 1; 
            }
            return dist;
        }



        //unused functions 
        string toBinaryString(int N) {
            string s;
            for(int i = N; i > 0; i = i / 2) {
                s = to_string(i % 2) + s;
            }
            return s;
        } 

        list<int> toBinaryIntList(int N) {
            list<int> l;
            for(int i = N; i > 0; i = i/2) {
                l.push_front(i%2);
            }
            return l;
        };


};

int main() {
    Solution sol;
    cout << "input number x: " << sol.toBinaryString(41) << endl;
    cout << "input number y: " << sol.toBinaryString(4) << endl << endl;
    cout << sol.hammingDistance(41, 4) << endl;
}






































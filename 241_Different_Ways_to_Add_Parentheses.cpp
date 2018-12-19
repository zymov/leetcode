/*
Given a string of numbers and operators, 
return all possible results from computing all the different possible ways to group numbers and operators. 
The valid operators are +, - and *.

Example 1:
Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2

Example 2:
Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> diffWaysToCompute(string input) {
      vector<int> result;
      for(int i = 0; i < input.size(); i++) {
        char c = input[i];
        if(c == '+' || c == '-' || c == '*') {
          vector<int> num1 = diffWaysToCompute(input.substr(0, i));
          vector<int> num2 = diffWaysToCompute(input.substr(i + 1));
          for(auto n1 : num1) {
            for(auto n2 : num2) {
              if(c == '+') result.push_back(n1 + n2);
              else if( c == '-') result.push_back(n1 - n2);
              else result.push_back(n1 * n2);
            }
          }
        }
      }
      if(result.empty()) {
        result.push_back(stoi(input));
      }
      return result;
    }


};

int main() {
  return 0;
}

/*


*/
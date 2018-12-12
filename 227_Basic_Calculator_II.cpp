/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
The integer division should truncate toward zero.

Example 1:
Input: "3+2*2"
Output: 7

Example 2:
Input: " 3/2 "
Output: 1

Example 3:
Input: " 3+5 / 2 "
Output: 5

Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
#include <iostream>
#include <stack>

using namespace std;

class Solution {
  public:
    int calculate(string s) {
      int res = 0, cur_res = 0, len = s.size();
      char op = '+';
      for(int i = 0; i < len; i++) {
        if(s[i] == ' ') continue;
        if(isdigit(s[i])) {
          int n = s[i] - '0';
          while(++i < len && isdigit(s[i])) {
            n = 10*n + (s[i] - '0');
          }
          i--;
          switch(op) {
            case '+': cur_res += n; break;
            case '-': cur_res -= n; break;
            case '*': cur_res *= n; break;
            case '/': cur_res /= n; break;
          }
        } else {
          if(s[i] == '+' || s[i] == '-') {
            res += cur_res;
            cur_res = 0;
          } 
          op = s[i];
        }
      }
      return res + cur_res;
    }
};

int main() {
  return 0;
}

/*


*/
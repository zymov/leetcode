/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:
Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

Example 1:
Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            set<string> operators = {"+", "-", "*", "/"};
            stack<int> stk;
            int len = tokens.size();
            for(int i = 0; i < len; i++) {
                string s = tokens[i];
                if(operators.count(s)) {
                    int op2 = stk.top(); stk.pop();
                    int op1 = stk.top(); stk.pop();
                    int result;
                    switch(s[0]) {
                        case '+':
                            result = op1 + op2;
                            break;
                        case '-':
                            result = op1 - op2;
                            break;
                        case '*':
                            result = op1 * op2;
                            break;
                        case '/':
                            result = op1 / op2;
                            break;
                    }
                    stk.push(result);
                } else {
                    stk.push(stoi(s));
                }
            }
            return stk.top();        
        }

        int evalRPN_Lambda(vector<string>& tokens) {
            unordered_map<string, function<int (int, int)> > map = {
                { "+", [] (int a, int b) { return a + b; }},
                { "-", [] (int a, int b) { return a - b; }},
                { "*", [] (int a, int b) { return a * b; }},
                { "/", [] (int a, int b) { return a / b; }},
            };
            stack<int> stk;
            for(string s : tokens) {
                if(!map.count(s)) stk.push(stoi(s));
                else {
                    int op2 = stk.top(); stk.pop();
                    int op1 = stk.top(); stk.pop();
                    stk.push(map[s](op1, op2));
                }
            }
            return stk.top();
        }
        
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
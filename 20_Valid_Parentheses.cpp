/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/


#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

class Solution {

    public:
        bool isValid(string s) {
            unordered_map<char, char> hash;
            hash['('] = ')';
            hash['['] = ']';
            hash['{'] = '}';            

            string prefix = "{([";
            
            vector<char> pairStack;

            for(int i = 0; i < s.length(); i++) {
                if(prefix.find(s[i]) != string::npos) {
                    pairStack.push_back(s[i]);
                } else if(pairStack.size() == 0) {  // check stack size first is important
                    return false;
                } else if( hash[pairStack.back()] != s[i] ) {   // the order makes back operation safe
                    return false;
                } else {
                    pairStack.pop_back();
                }
            }
            return pairStack.size() == 0;
        }


        bool notMySolution(string s) {
            stack<char> st;
            for(char c : s){
                if(c == '('|| c == '{' || c == '['){
                    st.push(c);
                }else{
                    if(st.empty()) return false;
                    if(c == ')' && st.top() != '(') return false;
                    if(c == '}' && st.top() != '{') return false;
                    if(c == ']' && st.top() != '[') return false;
                    st.pop();
                }
            }
            return st.empty();
        }
};

int main() {
    Solution sol;
    cout << sol.isValid("()[]") << endl;
    cout << sol.isValid("([])") << endl;
    cout << sol.isValid("([())") << endl;
    cout << sol.notMySolution(")])") << endl;
    return 0;
}
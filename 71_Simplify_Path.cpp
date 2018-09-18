/*
Given an absolute path for a file (Unix-style), simplify it. 

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "/a/../../b/../c//.//", => "/c"
path = "/a//b////c/d//././/..", => "/a/b/c"

In a UNIX-style file system, a period ('.') refers to the current directory, 
so it can be ignored in a simplified path. Additionally, a double period ("..") moves up a directory, 
so it cancels out whatever the last directory was. 
For more information, look here: https://en.wikipedia.org/wiki/Path_(computing)#Unix_style

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
#include <iostream>
#include <stack>

using namespace std;

class Solution {
    
    public:
        string simplifyPath(string path) {
            path += '/';
            int len = path.size();
            stack<string> s;
            string temp = "";
            for(int i = 1; i < len; i++) {
                if(path[i] == '/') {
                    if(temp == ".." && s.size() > 0) {
                        s.pop();
                    } else if(temp != "" && temp != ".") {
                        s.push(temp);
                    }
                    temp = "";
                } else {
                    temp += path[i];
                }
            }
            string res = "";
            while(s.size()) {
                if(s.top() == "..") {
                    break;
                }
                res = "/" + s.top() + res;
                s.pop();
            }
            return res.empty() ? "/" : res;
        }
};

int main() {
    Solution sol;
    sol.simplifyPath("/home/");
    sol.simplifyPath("/a/./b/../../c/");
    sol.simplifyPath("/a/../../b/../c//.//");
    sol.simplifyPath("/a//b////c/d//././/..");
    return 0;
}

/*
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "/a/../../b/../c//.//", => "/c"
path = "/a//b////c/d//././/..", => "/a/b/c"

*/
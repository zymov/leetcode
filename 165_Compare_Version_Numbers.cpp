/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", 
it is the fifth second-level revision of the second first-level revision.

Example 1:
Input: version1 = "0.1", version2 = "1.1"
Output: -1

Example 2:
Input: version1 = "1.0.1", version2 = "1"
Output: 1

Example 3:
Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int compareVersion(string version1, string version2) {
            vector<string> v1 = split(version1, '.');
            vector<string> v2 = split(version2, '.');
            int l1 = v1.size(), l2 = v2.size();
            int len = max(l1, l2);
            for(int i = 0; i < len; i++) {
                int vi1 = i < l1 ? stoi(v1[i]) : 0;
                int vi2 = i < l2 ? stoi(v2[i]) : 0;
                if(vi1 > vi2) return 1;
                else if(vi1 < vi2) return -1;
                else continue;
            }
            return 0;
        }

        vector<string> split(string s, char t) {
            int lastIndex = 0, len = s.size();
            vector<string> res;
            int i = 0;
            for(; i < len; i++) {
                if(s[i] == t) {
                    res.push_back(s.substr(lastIndex, i - lastIndex));
                    lastIndex = i + 1;
                }
            }
            if(lastIndex < i) {
                res.push_back(s.substr(lastIndex, i - lastIndex));
            }
            return res;
        }
};

int main() {
    Solution sol;
    string a = "a b casd a dqw w";
    vector<string> r = sol.split(a, ' ');
    for(int i = 0; i < r.size(); i++) {
        cout << r[i] << "  ";
    }
    cout << endl;
    return 0;
}

/*


*/
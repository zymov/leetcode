/*
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/
#include <iostream>

using namespace std;

class Solution {

    public:

        int strStr_BruteForce(string haystack, string needle) {
            int m = haystack.size(), n = needle.size();
            for (int i = 0; i <= m - n; i++) {
                int j = 0;
                for (; j < n; j++) {
                    if (haystack[i + j] != needle[j]) {
                        break;
                    }
                }
                if (j == n) {
                    return i;
                }
            }
            return -1;
        }

        int strStr_BruteForceBack(string haystack, string needle) {
            if(needle == "") return 0;
            int j = 0, i = 0;
            int H = haystack.length();
            int N = needle.length();
            for(; i < H && j < N; i++) {
                if(haystack[i] == needle[j]) j++;
                else {
                    i -= j;
                    j = 0;
                }
            }
            if(j == N) return i - N;
            else return -1;
        }

        int strstr_KMP(string haystack, string needle) {
            if(needle == "") return 0;
            int i = 0, j = 0, H = haystack.length(), N = needle.length();
            int dfs[N];
            computeDFS(needle, N, dfs);
            while(i < H) {
                if(haystack[i] == needle[j]) {
                    i++;
                    j++;
                } 
                if(j == N) {
                    return i - j;
                } else if (i < H && needle[j] != haystack[i]) {
                    if(j != 0) {
                        j = dfs[j - 1];
                    } else {
                        i++;
                    }
                }
            }
            return -1;
        }

        void computeDFS(string pat, int M, int *lps) {
            int len = 0, i = 1;
            lps[0] = 0; 

            while (i < M) {
                if (pat[i] == pat[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                } else {
                    if (len != 0) {
                        len = lps[len-1];
                    } else { 
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }

        
        
};

int main() {
    Solution sol;
    cout << sol.strstr_KMP("", "a") << endl;
    return 0;
}
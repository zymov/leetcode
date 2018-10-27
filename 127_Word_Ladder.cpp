/*
Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> dict(wordList.begin(), wordList.end());
            if(!dict.count(endWord)) return 0;
            unordered_set<string> q1{beginWord};
            unordered_set<string> q2{endWord};
            int len = beginWord.length();
            int step = 0;
            while(!q1.empty() && !q2.empty()) {
                step++;
                if(q1.size() > q2.size()) {     // always expend the smaller queue first
                    swap(q1, q2);
                }
                unordered_set<string> q;
                for(string word : q1) {
                    for(int i = 0; i < len; i++) {
                        char temp = word[i];
                        for(int j = 'a'; j < 'z'; j++) {
                            word[i] = j;
                            if(q2.count(word)) return step + 1;
                            if(!dict.count(word)) continue;
                            dict.erase(word);
                            q.insert(word);
                        }
                        word[i] = temp;
                    }
                }
                swap(q, q1);    // set q1 to new queue 
            }
            return 0;
        }
};

int main() {
    Solution sol;
    return 0;
}

/*


*/
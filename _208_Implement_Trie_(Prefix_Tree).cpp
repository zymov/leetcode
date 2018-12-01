/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class TrieNode {
  public:
    TrieNode* next[26];
    bool isEnd;
    TrieNode(bool b = false) {
      memset(next, 0, sizeof(next));
      isEnd = b;
    }
};

class Trie {
  public:
    /** Initialize your data structure here. */
    Trie() { }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      TrieNode* p = root;
      for(int i = 0; i < word.size(); i++) {
        if(p->next[word[i] - 'a'] == NULL) {
          p->next[word[i] - 'a'] = new TrieNode();
        }
        p = p->next[word[i] - 'a'];
      }
      p->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      TrieNode* p = find(word);
      return p != NULL && p->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      return find(prefix) != NULL;
    }
  private:
    TrieNode* root = new TrieNode();
    TrieNode* find(string s) {
      TrieNode* p = root;
      for(int i = 0; i < s.size() && p != NULL; i++) {
        p = p->next[s[i] - 'a'];
      }
      return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

/*


*/
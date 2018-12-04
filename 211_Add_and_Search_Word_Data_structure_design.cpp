/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z.
*/
#include <iostream>

using namespace std;

class WordNode {
  public: 
    bool isWord = false;
    WordNode* next[26]{};
    WordNode* get(char c) {
      return next[c - 'a'];
    }
    void add(char c) {
      next[c - 'a'] = new WordNode();
    }
};

class WordDictionary {
  public:
    /** Initialize your data structure here. */
    WordDictionary() {
      
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
      WordNode* w = root;
      for(auto c : word) {
        if(!w->get(c)) w->add(c);
        w = w->get(c);
      }
      w->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
      return find(word, 0, root);
    }

  private:
    WordNode* root = new WordNode();
    bool find(string& word, int pos, WordNode* root) {
      if(pos == word.size()) return root->isWord;
      if(word[pos] != '.') {
        root = root->get(word[pos]);
        return root ? find(word, pos + 1, root) : false;
      }
      for(int i = 0; i < 26; i++) {
        if(root->next[i] && find(word, pos + 1, root->next[i]))
          return true;
      }
      return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */


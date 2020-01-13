import collections

class TrieNode():
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.isWord = False

class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        node = self.root
        for w in word:
            node = node.children[w]
        node.isWord = True

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        node = self.root
        self.isMatch = False
        self.dfs(node, word)
        return self.isMatch

    def dfs(self, node: TrieNode, word: str):
        if not word:
            if node.isWord:
                self.isMatch = True
            return
        if word[0] == '.':
            for n in node.children.values():
                self.dfs(n, word[1:])
        else:
            node = node.children.get(word[0])
            if not node:
                return
            self.dfs(node, word[1:])



sol = WordDictionary()
sol.addWord('asd')
sol.addWord('as')
sol.addWord('tree')
# for i in sol.root.children:
#     if i.children:
#         for j in i.children:
#             print(j)
#     else:
#         print('root -- ', i)

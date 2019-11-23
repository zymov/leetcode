class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        s, s1, s2 = set(wordList), {beginWord}, {endWord}
        if endWord not in s:
            return 0
        l = len(beginWord)
        step = 0
        while len(s1) and len(s2):
            step += 1
            if len(s1) > len(s2):
                s1, s2 = s2, s1
            tmp = set()
            for word in s1:
                for i in range(len(word)):
                    ch = word[i]
                    for j in range(26):
                        word = word[:i] + chr(ord('a') + j) + word[i + 1:]
                        if word in s2:
                            return step + 1
                        if word not in s:
                            continue
                        s.remove(word)
                        tmp.add(word)
                    word = word[:i] + ch + word[i + 1:]
            tmp, s1 = s1, tmp
        return 0


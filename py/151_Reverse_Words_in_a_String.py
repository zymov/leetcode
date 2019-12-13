class Solution:
    def reverseWords(self, s: str) -> str:
        s = s[::-1]
        word = ''
        words = ''
        for i, c in enumerate(s):
            if c != ' ' and word != '' and s[i - 1] == ' ':
                words += word + ' '
                word = c
            elif c != ' ':
                word = c + word
            else:
                continue
        words += word
        return words

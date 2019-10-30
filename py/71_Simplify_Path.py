class Solution:
    def simplifyPath(self, path: str) -> str:
        if not len(path):
            return ''
        stack = []
        ls = path.split('/')
        for x in ls:
            if x == '' or x == '.':
                continue
            elif x == '..':
                if stack:
                    stack.pop()
            else:
                stack.append(x)
        return '/' + '/'.join(stack)

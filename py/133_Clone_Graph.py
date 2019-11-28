# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        dic = {}
        def dfs(node: 'Node'):
            if not node:
                return
            nodeCopy = Node(node.val, [])
            dic[node] = nodeCopy
            for nei in node.neighbors:
                if nei in dic:
                    nodeCopy.neighbors.append(dic[nei])
                else:
                    nodeCopy.neighbors.append(dfs(nei))
            return nodeCopy
        return dfs(node)

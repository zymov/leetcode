from typing import List
import collections

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        course = {i: set() for i in range(numCourses)}
        pre = collections.defaultdict(set)

        for i, j in prerequisites:
            course[i].add(j)
            pre[j].add(i)

        queue = collections.deque([i for i in course if not course[i]])
        count, res = 0, []

        while queue:
            node = queue.popleft()
            res.append(node)
            count += 1
            for i in pre[node]:
                course[i].remove(node)
                if not course[i]:
                    queue.append(i)
        return res if count == numCourses else []

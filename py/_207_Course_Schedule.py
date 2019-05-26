"""
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
"""
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        visitied = [False for x in range(numCourses)]
        onPath = [False for x in range(numCourses)]    # current visiting node
        graph = [[] for x in range(numCourses)]
        for course, preCourse in prerequisites:
            graph[course].append(preCourse)
        for x in range(numCourses):
            if self.hasCircle(visitied, onPath, graph, x):
                return False
        return True

    def hasCircle(self, visitied: List[int], onPath: List[int], graph: List[List[int]], cur: int) -> bool:
        if visitied[cur]: return False
        if onPath[cur]: return True
        visitied[cur] = onPath[cur] = True
        for x in graph[cur]:
            if onPath[x] or self.hasCircle(visitied, onPath, graph, x):
                return True
        onPath[cur] = False
        return False

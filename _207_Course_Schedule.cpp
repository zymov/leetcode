/*
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
*/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    public:
        bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
            vector<unordered_set<int>> graph(numCourses);
            for(auto p : prerequisites) {
                graph[p.second].insert(p.first);
            }
            vector<int> visited(numCourses, false), onPath(numCourses, false);
            for(int i = 0; i < numCourses; i++) {
                if(!visited[i] && DFS_cycle(visited, onPath, graph, i))
                    return false;
            }
            return true;
        }

        bool DFS_cycle(vector<int>& visited, vector<int>& onPath, vector<unordered_set<int>>& graph, int course){
            visited[course] = onPath[course] = true;
            for(int neigh : graph[course]) {
                if(onPath[neigh] || DFS_cycle(visited, onPath, graph, neigh))
                    return true;
            }
            return onPath[course] = false;
        }
};

int main() {
    return 0;
}

/*


*/
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.


Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses

*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //We do a topological sort of the courses.
        //If we can do it, it means all courses can be taken. Otherwise
        //we have a cycle and they can't be taken.
        //Complexity: O(numCourses + len(prerequisites)) - time, O(numCourses + len(prerequisites)) - space
        queue<int> q;
        vector<int> inDegree(numCourses, 0);
        vector<int> adj[numCourses];

        for(auto edge : prerequisites){
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        for(int i = 0; i < numCourses; i++)
            if(inDegree[i] == 0)
                q.push(i);

        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto neighbor : adj[v]){
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        for(int i = 0; i < numCourses; i++)
            if(inDegree[i])
                return false;
        
        return true;
    }
};

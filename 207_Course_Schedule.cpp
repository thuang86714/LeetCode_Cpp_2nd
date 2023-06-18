/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

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
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //credit to dw70
        //topological sorting, TC O(V+E), SC O(V+E)
        vector<vector<int>> graph(numCourses);
        vector<int> degree(numCourses, 0);
        queue<int> zeroDegree;
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }

        for(int i = 0; i < degree.size(); i++){
            if(degree[i] == 0){
                zeroDegree.push(i);
                numCourses--;
            }
        }

        while(!zeroDegree.empty()){
            int node = zeroDegree.front();
            zeroDegree.pop();
            for(int i = 0; i < graph[node].size(); i++){
                int connectedNode = graph[node][i];
                degree[connectedNode]--;
                if(degree[connectedNode] == 0){
                    zeroDegree.push(connectedNode);
                    numCourses--;
                }
            }
        }
        return numCourses == 0;

    }
};
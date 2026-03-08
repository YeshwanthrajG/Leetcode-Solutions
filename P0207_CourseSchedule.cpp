/* 
Problem ID : 207 

Problem : Course Schedule

Statement : There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take 
course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/course-schedule/description/
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses], ind(numCourses,0), ans;
        for(auto x:prerequisites){
            adj[x[0]].push_back(x[1]);
            ind[x[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0) q.push(i);
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans.push_back(it);
            for(auto x:adj[it]){
                ind[x]--;
                if(ind[x]==0) q.push(x);
            }
        }
        return numCourses==ans.size();
    }
};
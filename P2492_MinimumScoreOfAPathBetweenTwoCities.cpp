/* 
Problem ID : 2492 

Problem : Minimum Score of a Path Between Two Cities

Statement : You are given a positive integer n representing n cities numbered from 1 to n. 
You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a 
bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not 
necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n 
multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
*/

/* Problem Link
https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/?envType=daily-question&envId=2026-07-04
*/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &i:roads){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<bool> v(n+1, false);
        queue<int> q;

        q.push(1);
        v[1]=true;
        int res=INT_MAX;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &[neigh, w]:adj[node]){
                res=min(res, w);
                if(!v[neigh]){
                    v[neigh]=true;
                    q.push(neigh);
                }
            }
        }
        return res;
    }
};
/* 
Problem ID : 3650 

Problem : Minimum Cost Path with Edge Reversals

Statement : You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, 
and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi 
with cost wi.

Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used 
its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and 
immediately traverse it.

The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.

Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/?envType=daily-question&envId=2026-01-27
*/

class Solution {
public:
vector<vector<pair<int, int>>> G;
    int dijkstra(int n){
        vector<bool> vis(n, false);
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>> Q;
        Q.push({0,0});
        dist[0]=0;
        while(!Q.empty()){
            int u=Q.top().second;
            Q.pop();
            if(vis[u]) continue;
            vis[u]=true;
            for(auto [v,w]:G[u]){
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    Q.push({-dist[v],v});
                }
            }
        }
        if(dist[n-1]==1e9) return -1;
        return dist[n-1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        G.resize(n);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            G[u].push_back({v,w});
            G[v].push_back({u,2*w});
        }
        return dijkstra(n);
    }
};
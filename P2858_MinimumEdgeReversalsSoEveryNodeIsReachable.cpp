/* 
Problem ID : 2858 

Problem : Minimum Edge Reversals So Every Node Is Reachable

Statement : There is a simple directed graph with n nodes labeled from 0 to n - 1. The graph would 
form a tree if its edges were bi-directional.

You are given an integer n and a 2D integer array edges, where edges[i] = [ui, vi] represents a 
directed edge going from node ui to node vi.

An edge reversal changes the direction of an edge, i.e., a directed edge going from node ui to node vi 
becomes a directed edge going from node vi to node ui.

For every node i in the range [0, n - 1], your task is to independently calculate the minimum number of 
edge reversals required so it is possible to reach any other node starting from node i through a sequence 
of directed edges.

Return an integer array answer, where answer[i] is the minimum number of edge reversals required so it 
is possible to reach any other node starting from node i through a sequence of directed edges.
*/

/* Problem Link
https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/description/
*/

class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> G(n);
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            G[u].emplace_back(v, 1);
            G[v].emplace_back(u, -1);
        }
        vector<int> res(n,0);
        auto d1=[&](auto &&self, int u, int p)->void{
            for(auto [v,w]:G[u]){
                if(p==v) continue;
                if(w<0) res[0]++;
                self(self,v,u);
            }
        };
        d1(d1, 0, -1);

        auto d2=[&](auto &&self, int u, int p)->void{
            for(auto [v,w]:G[u]){
                if(p==v) continue;
                res[v]=res[u]+w;
                self(self, v,u);
            }
        };
        d2(d2, 0, -1);
        return res;
    }
};
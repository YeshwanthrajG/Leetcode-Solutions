/* 
Problem ID : 3820 

Problem : Pythagorean Distance Nodes in a Tree

Statement : You are given an integer n and an undirected tree with n nodes numbered from 0 to n - 1. 
The tree is represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi] indicates an 
undirected edge between ui and vi.

You are also given three distinct target nodes x, y, and z.

For any node u in the tree:

Let dx be the distance from u to node x
Let dy be the distance from u to node y
Let dz be the distance from u to node z
The node u is called special if the three distances form a Pythagorean Triplet.

Return an integer denoting the number of special nodes in the tree.

A Pythagorean triplet consists of three integers a, b, and c which, when sorted in ascending order, 
satisfy a2 + b2 = c2.

The distance between two nodes in a tree is the number of edges on the unique path between them.
*/

/* Problem Link
https://leetcode.com/problems/pythagorean-distance-nodes-in-a-tree/description/
*/

class Solution {
public:
    vector<int> bfs(int start, vector<vector<int>>&adj){
        int n=adj.size();
        vector<int> dist(n,-1);
        queue<int> q;
        dist[start]=0;
        q.push(start);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int y:adj[x]){
                if(dist[y]==-1){
                    dist[y]=dist[x]+1;
                    q.push(y);
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> dx=bfs(x,adj);
        vector<int> dy=bfs(y,adj);
        vector<int> dz=bfs(z,adj);
        int count=0;
        for(int i=0;i<n;i++){
            vector<int> d={dx[i], dy[i], dz[i]};
            sort(d.begin(),d.end());
            long long a=d[0], b=d[1], c=d[2];
            if(a*a+b*b==c*c) count++;
        }
        return count;
    }
};
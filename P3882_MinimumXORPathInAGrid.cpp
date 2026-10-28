/* 
Problem ID : 3882 

Problem : Minimum XOR Path in a Grid

Statement : You are given a 2D integer array grid of size m * n.

You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).

At each step, you may move either right or down.

The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, 
including the start and end cells.

Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).
*/

/* Problem Link
https://leetcode.com/problems/minimum-xor-path-in-a-grid/description/?envType=daily-question&envId=2026-10-28
*/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        queue<tuple<int, int, int>> q;
        int st=grid[0][0];
        q.push({0, 0, st});
        vis[0][0][st]=true;
        int dx[2]={0,1}, dy[2]={1, 0};
        while(!q.empty()){
            auto [x,y,curr]=q.front();
            q.pop();
            for(int i=0;i<2;i++){
                int tx=x+dx[i];
                int ty=y+dy[i];
                if(tx<m && ty<n){
                    int newCurr=curr^grid[tx][ty];
                    if(!vis[tx][ty][newCurr]) {
                        vis[tx][ty][newCurr]=true;
                        q.push({tx, ty, newCurr});
                    }
                }
            }
        }
        for(int i=0;i<1024;i++){
            if(vis[m-1][n-1][i]) return i;
        }
        return -1;
    }
};
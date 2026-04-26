/* 
Problem ID : 1559 

Problem : Detect Cycles in 2D Grid

Statement : Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle 
consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given 
cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or 
right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle 
(1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited 
cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/detect-cycles-in-2d-grid/description/?envType=daily-question&envId=2026-04-26
*/

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int dr[4]={1, -1, 0, 0}, dc[4]={0, 0, 1, -1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]) continue;
                vector<array<int, 4>> v;
                v.push_back({i, j, -1, -1});
                vis[i][j]=true;
                while(!v.empty()){
                    auto curr=v.back();
                    v.pop_back();
                    int xr=curr[0], xc=curr[1], yr=curr[2], yc=curr[3];
                    for(int k=0;k<4;k++){
                        int nr=xr+dr[k];
                        int nc=xc+dc[k];
                        if(nr<0 || nr>=m || nc<0 || nc>=n) continue;
                        if(grid[nr][nc]!=grid[xr][xc]) continue;
                        if(nr==yr && nc==yc) continue;
                        if(vis[nr][nc]) return true;
                        vis[nr][nc]=true;
                        v.push_back({nr, nc, xr, xc});
                    }
                }
            }
        }
        return false;
    }
};
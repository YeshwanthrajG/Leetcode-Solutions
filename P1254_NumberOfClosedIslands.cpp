/* 
Problem ID : 1254 

Problem : Number of Closed Islands

Statement : Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 
4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, 
bottom) surrounded by 1s.

Return the number of closed islands.
*/

/* Problem Link
https://leetcode.com/problems/number-of-closed-islands/description/?envType=daily-question&envId=2026-10-25
*/

class Solution {
public:
    int m, n;
    bool isClosed(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n) return false;
        if(grid[i][j]) return true;
        grid[i][j]=1;
        return isClosed(grid, i+1, j) & isClosed(grid, i-1, j) & isClosed(grid, i, j+1) & isClosed(grid, i, j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]) res+=isClosed(grid, i, j);
            }
        }
        return res;
    }
};
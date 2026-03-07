/* 
Problem ID : 200 

Problem : Number of Islands

Statement : Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.
*/

/* Problem Link
https://leetcode.com/problems/number-of-islands/description/
*/

class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 ||j>=grid[0].size() || grid[i][j]!='1') return ;
        grid[i][j]='0';
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int res=0;
        int n=grid.size(), m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1') {
                    res++;
                    dfs(grid, i,j);
                }
            }
        }
        return res;
    }

};
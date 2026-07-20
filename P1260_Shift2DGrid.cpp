/* 
Problem ID : 1260 

Problem : Shift 2D Grid

Statement : Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.
*/

/* Problem Link
https://leetcode.com/problems/shift-2d-grid/description/?envType=daily-question&envId=2026-07-20
*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k==0) return grid;
        int row=grid.size(), col=grid[0].size();
        int n=row*col;
        k%=n;
        if(k==0) return grid;
        vector<vector<int>> res(row, vector<int>(col));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int oIdx=i*col+j;
                int nIdx=(oIdx+k)%n;
                int nR=nIdx/col, nC=nIdx%col;
                res[nR][nC]=grid[i][j];
            }
        }
        return res;
    }
};
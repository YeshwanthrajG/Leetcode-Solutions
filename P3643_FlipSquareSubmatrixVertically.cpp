/* 
Problem ID : 3643 

Problem : Flip Square Submatrix Vertically

Statement : You are given an m x n integer matrix grid, and three integers x, y, and k.

The integers x and y represent the row and column indices of the top-left corner of a square 
submatrix and the integer k represents the size (side length) of the square submatrix.

Your task is to flip the submatrix by reversing the order of its rows vertically.

Return the updated matrix.
*/

/* Problem Link
https://leetcode.com/problems/flip-square-submatrix-vertically/?envType=daily-question&envId=2026-03-21
*/

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // int m=grid.size(), n=grid[0].size();
        for(int i=0;i<k/2;i++){
            for(int j=0;j<k;j++){
                swap(grid[x+i][y+j], grid[(x+k-i-1)][y+j]);
            }
        }
        return grid;
    }
};
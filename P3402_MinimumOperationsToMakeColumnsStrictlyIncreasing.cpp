/* 
Problem ID : 3402 

Problem : Minimum Operations to Make Columns Strictly Increasing

Statement : You are given a m x n matrix grid consisting of non-negative integers.

In one operation, you can increment the value of any grid[i][j] by 1.

Return the minimum number of operations needed to make all columns of grid strictly increasing.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/description/
*/

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ops=0;
        for(int i=0;i<grid[0].size();i++){
            for(int j=1;j<grid.size();j++){
                if(grid[j][i]<=grid[j-1][i]){
                    int temp=grid[j-1][i]-grid[j][i]+1;
                    ops+=temp;
                    grid[j][i]+=temp;
                }
            }
        }
        return ops;
    }
};
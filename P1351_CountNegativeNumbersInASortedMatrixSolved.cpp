/* 
Problem ID : 1351 

Problem : Count Negative Numbers in a Sorted Matrix

Statement : Given a m x n matrix grid which is sorted in non-increasing order both row-wise and 
column-wise, return the number of negative numbers in grid.
*/

/* Problem Link
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/?envType=daily-question&envId=2025-12-28
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]<0){
                    count+=grid[i].size()-j;
                    break;
                }
            }
        }
        return count;
    }
};
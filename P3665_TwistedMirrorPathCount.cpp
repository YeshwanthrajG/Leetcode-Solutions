/* 
Problem ID : 3665 

Problem : Twisted Mirror Path Count

Statement : Given an m x n binary grid grid where:

grid[i][j] == 0 represents an empty cell, and
grid[i][j] == 1 represents a mirror.
A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right 
corner (m - 1, n - 1). It can move only right or down. If the robot attempts to move into a 
mirror cell, it is reflected before entering that cell:

If it tries to move right into a mirror, it is turned down and moved into the cell directly 
below the mirror.
If it tries to move down into a mirror, it is turned right and moved into the cell directly to 
the right of the mirror.
If this reflection would cause the robot to move outside the grid boundaries, the path is 
considered invalid and should not be counted.

Return the number of unique valid paths from (0, 0) to (m - 1, n - 1).

Since the answer may be very large, return it modulo 109 + 7.

Note: If a reflection moves the robot into a mirror cell, the robot is immediately reflected 
again based on the direction it used to enter that mirror: if it entered while moving right, it 
will be turned down; if it entered while moving down, it will be turned right. This process will 
continue until either the last cell is reached, the robot moves out of bounds or the robot moves to 
a non-mirror cell.
*/

/* Problem Link
https://leetcode.com/problems/twisted-mirror-path-count/description/?envType=daily-question&envId=2026-10-31
*/

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int mod=1e9+7;
        int n=grid[0].size();
        vector<int> res(n);
        res[0]=1;
        for(auto &row:grid){
            int r=0;
            for(int i=0;i<row.size();i++){
                if(row[i]) swap(res[i], r);
                else{
                    res[i]=(r+res[i])%mod;
                    r=res[i];
                }
            }
        }
        return res.back();
    }
};
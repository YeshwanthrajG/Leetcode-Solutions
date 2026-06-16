/* 
Problem ID : 62 

Problem : Unique Paths

Statement : There is a robot on an m x n grid. The robot is initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to 
reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/

/* Problem Link
https://leetcode.com/problems/unique-paths/description/
*/

// Approach 1

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> above(n, 1);
        for(int r=1;r<m;r++){
            vector<int> curr(n, 1);
            for(int c=1;c<n;c++){
                curr[c]=curr[c-1]+above[c];
            }
            above=curr;
        }
        return above[n-1];
    }
};

// Approach 2

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> above(n, 1);
        for(int r=1;r<m;r++){
            vector<int> curr(n, 1);
            for(int c=1;c<n;c++){
                curr[c]=curr[c-1]+above[c];
            }
            above=curr;
        }
        return above[n-1];
    }
};
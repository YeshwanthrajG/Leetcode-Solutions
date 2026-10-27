/* 
Problem ID : 3963 

Problem : Create Grid With Exactly One Path

Statement : You are given two integers m and n, representing the number of rows and columns of a grid.

Construct any m x n grid consisting only of the characters '.' and '#', where:

'.' represents a free cell.
'#' represents an obstacle cell.
A valid path is a sequence of free cells that:

Starts at the top-left cell (0, 0).
Ends at the bottom-right cell (m - 1, n - 1).
Moves only:
Right, from (i, j) to (i, j + 1), or
Down, from (i, j) to (i + 1, j).
Return any grid such that there is exactly one valid path from the top-left cell to the bottom-right cell.
*/

/* Problem Link
https://leetcode.com/problems/create-grid-with-exactly-one-path/description/?envType=daily-question&envId=2026-10-27
*/

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m, string(n, '#'));
        int row=0, col=0;
        res[row][col]='.';
        while(row<m-1 || col<n-1){
            if(row<m-1 && (col==n-1 || abs((row+1)*(n-1)-col*(m-1))<=abs(row*(n-1)-(col+1)*(m-1))))   row++;
            else col++;
            res[row][col]='.';
        }
        return res;
    }
};
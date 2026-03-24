/* 
Problem ID : 118 

Problem : Pascal's Triangle

Statement : Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.
*/

/* Problem Link
https://leetcode.com/problems/pascals-triangle/description/
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0].push_back(1);
        for(int i=1;i<numRows;i++){
            res[i].resize(i+1);
            res[i][0]=res[i][i]=1;
            for(int j=1;j<=(i/2);j++){
                res[i][j]=res[i-1][j-1]+res[i-1][j];
                res[i][i-j]=res[i-1][j-1]+res[i-1][j];
            }
        }
        return res;
    }
};
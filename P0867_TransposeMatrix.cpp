/* 
Problem ID : 867 

Problem : Transpose Matrix

Statement : Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and 
column indices.
*/

/* Problem Link
https://leetcode.com/problems/transpose-matrix/description/
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[j][i]=matrix[i][j];
            }
        }
        return res;
    }
};
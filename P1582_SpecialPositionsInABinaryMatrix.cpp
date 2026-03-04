/* 
Problem ID : 1582 

Problem : Special Positions in a Binary Matrix

Statement : Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other 
elements in row i and column j are 0 (rows and columns are 0-indexed).
*/

/* Problem Link
https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2026-03-04
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> rows(m,0), columns(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) {
                    rows[i]++;
                    columns[j]++;
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && rows[i]==1 && columns[j]==1) res++;
            }
        }
        return res;
    }
};
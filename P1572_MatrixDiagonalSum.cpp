/* 
Problem ID : 1572 

Problem : Matrix Diagonal Sum

Statement : Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary 
diagonal that are not part of the primary diagonal.
*/

/* Problem Link
https://leetcode.com/problems/matrix-diagonal-sum/description/?envType=problem-list-v2&envId=n11ydiyj
*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++){
            sum+=mat[i][i];
            sum+=mat[i][n-i-1];
        }
        if(n%2==1) sum-=mat[n/2][n/2];
        return sum;
    }
};
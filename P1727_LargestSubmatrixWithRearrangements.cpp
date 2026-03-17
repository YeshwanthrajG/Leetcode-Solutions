/* 
Problem ID : 1727 

Problem : Largest Submatrix With Rearrangements

Statement : You are given a binary matrix matrix of size m x n, and you are allowed 
to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the 
submatrix is 1 after reordering the columns optimally.
*/

/* Problem Link
https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2026-03-17
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        int area=0;
        for(int i=0;i<m;i++){
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for(int j=0;j<n;j++){
                area=max(area, matrix[i][j]*(j+1));
            }
        }
        return area;
    }
};
/* 
Problem ID : 1886 

Problem : Determine Whether Matrix Can Be Obtained By Rotation

Statement : Given two n x n binary matrices mat and target, return true if it is possible to make mat 
equal to target by rotating mat in 90-degree increments, or false otherwise.
*/

/* Problem Link
https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/?envType=daily-question&envId=2026-03-22
*/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<bool> res(4,true);
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j]) res[0]=false;
                if(mat[i][j]!=target[j][n-i-1]) res[1]=false;
                if(mat[i][j]!=target[n-i-1][n-j-1]) res[2]=false;
                if(mat[i][j]!=target[n-j-1][i]) res[3]=false;
            }
        }
        return (res[0]||res[1]||res[2]||res[3]);
    }
};
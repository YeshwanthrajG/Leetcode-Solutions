/* 
Problem ID : 85 

Problem : Maximal Rectangle

Statement : Given a rows x cols binary matrix filled with 0's and 1's, find the 
largest rectangle containing only 1's and return its area.
*/

/* Problem Link
https://leetcode.com/problems/maximal-rectangle/description/
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> mat(m, vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) mat[i][j]=matrix[i][j]-'0';
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]==1) mat[i][j]+=mat[i][j-1];
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int w=mat[j][i];
                if(w==0) continue;
                int curr=w;
                for(int k=j;k<m&&mat[k][i]>0;k++){
                    curr=min(curr, mat[k][i]);
                    int h=k-j+1;
                    res=max(res, curr*h);
                }
                curr=w;
                for(int k=j;k>=0&&mat[k][i]>0;k--){
                    curr=min(curr, mat[k][i]);
                    int h=j-k+1;
                    res=max(res, curr*h);
                }
            }
        }
        return res;
    }
};
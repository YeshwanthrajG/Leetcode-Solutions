/* 
Problem ID : 2906 

Problem : Construct Product Matrix

Statement : Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p 
of size n * m as the product matrix of grid if the following condition is met:

Each element p[i][j] is calculated as the product of all elements in grid except for the element 
grid[i][j]. This product is then taken modulo 12345.
Return the product matrix of grid.
*/

/* Problem Link
https://leetcode.com/problems/construct-product-matrix/description/?envType=daily-question&envId=2026-03-24
*/

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD=12345;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> pre(n, vector<int>(m));
        long long suff=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                pre[i][j]=suff;
                suff=(suff*(grid[i][j]%MOD))%MOD;
            }
        }
        long long pref=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i][j]=(pre[i][j]*pref)%MOD;
                pref=(pref*(grid[i][j]%MOD))%MOD;
            }
        }
        return pre;
    }
};
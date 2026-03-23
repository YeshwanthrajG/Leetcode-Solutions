/* 
Problem ID : 1594 

Problem : Maximum Non Negative Product in a Matrix

Statement : You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), 
and in each step, you can only move right or down in the matrix.

Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner 
(m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product 
of all integers in the grid cells visited along the path.

Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.

Notice that the modulo is performed after getting the maximum product.
*/

/* Problem Link
https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/?envType=daily-question&envId=2026-03-23
*/

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int MOD=1e9+7;
        vector<vector<long long>> maxP(m, vector<long long>(n));
        vector<vector<long long>> minP(m, vector<long long>(n));
        maxP[0][0]=minP[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            maxP[i][0]=minP[i][0]=maxP[i-1][0]*grid[i][0];
        }
        for(int j=1;j<n;j++){
            maxP[0][j]=minP[0][j]=minP[0][j-1]*grid[0][j];
        }
        long res=0;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                long temp=grid[i][j];
                long w=maxP[i][j-1]*temp;
                long x=minP[i][j-1]*temp;
                long y=maxP[i-1][j]*temp;
                long z=minP[i-1][j]*temp;

                maxP[i][j]=max({w,x,y,z});
                minP[i][j]=min({w,x,y,z});
            }
        }
        res=max(maxP[m-1][n-1], minP[m-1][n-1]);
        if(res<0) return -1;
        return res%MOD;
    }
};
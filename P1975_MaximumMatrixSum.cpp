/* 
Problem ID : 1975 

Problem : Maximum Matrix Sum

Statement : You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the 
matrix's elements using the operation mentioned above.
*/

/* Problem Link
https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05
*/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int small=INT_MAX;
        int n=matrix.size();
        long long sum=0;
        int neg_count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int temp=matrix[i][j];
                if(temp<0) neg_count++;
                temp=abs(temp);
                sum+=temp;
                small=min(small, temp);
            }
        }
        if(neg_count%2==0) return sum;
        return sum-2*small;
    }
};
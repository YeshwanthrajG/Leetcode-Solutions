/* 
Problem ID : 1458 

Problem : Max Dot Product of Two Subsequences

Statement : Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).
*/

/* Problem Link
https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2026-01-08
*/

class Solution {
public: 
    vector<int> nums1, nums2;
    vector<vector<int>> memo;
    int n,m;
    const int NEG_INF=-1e9;
    int dp(int i, int j){
        if(i==n || j==m){
            return NEG_INF;
        }
        if(memo[i][j]!=INT_MIN){
            return memo[i][j];
        }
        int t=nums1[i]*nums2[j];
        int res=max({t+dp(i+1, j+1), t, dp(i+1, j), dp(i,j+1)});
        memo[i][j]=res;
        return memo[i][j];
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        nums1=a;
        nums2=b;
        n=nums1.size();
        m=nums2.size();
        memo.assign(n, vector<int>(m,INT_MIN));
        return dp(0,0);
    }
};
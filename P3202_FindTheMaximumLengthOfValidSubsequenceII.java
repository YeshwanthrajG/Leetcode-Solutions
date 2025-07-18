/* 
Problem ID : 3202 

Problem : Find the Maximum Length of Valid Subsequence II

Statement : You are given an integer array nums and a positive integer k.
A subsequence sub of nums with length x is called valid if it satisfies:
(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.

Return the length of the longest valid subsequence of nums.
*/

/* Problem Link
https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/?envType=daily-question&envId=2025-07-17
*/

class Solution {
    public int maximumLength(int[] nums, int k) {
        int dp[][]=new int[k][k];
        int res=0;
        for(int i:nums){
            int x=i%k;
            for(int y=0;y<k;y++){
                dp[x][y]=dp[y][x]+1;
                res=Math.max(res,dp[x][y]);
            }
            
        }
        return res;
    }
}
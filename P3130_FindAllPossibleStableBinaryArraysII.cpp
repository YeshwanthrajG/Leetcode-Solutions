/* 
Problem ID : 3130 

Problem : Find All Possible Stable Binary Arrays II

Statement : You are given 3 positive integers zero, one, and limit.

A binary array arr is called stable if:

The number of occurrences of 0 in arr is exactly zero.
The number of occurrences of 1 in arr is exactly one.
Each subarray of arr with a size greater than limit must contain both 0 and 1.
Return the total number of stable binary arrays.

Since the answer may be very large, return it modulo 109 + 7.
*/

/* Problem Link
https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/description/?envType=daily-question&envId=2026-03-10
*/

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD=1e9+7;
        vector<vector<array<long,2>>> dp(zero+1, vector<array<long, 2>>(one+1, {0,0}));
        for(int i=1;i<=min(zero, limit);i++) dp[i][0][0]=1;
        for(int j=1;j<=min(one, limit);j++) dp[0][j][1]=1;
        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){
                long res0=(i-limit>=1)?dp[i-limit-1][j][1]:0;
                long res1=(j-limit>=1)?dp[i][j-limit-1][0]:0;
                dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]-res0+MOD)%MOD;
                dp[i][j][1]=(dp[i][j-1][0]+dp[i][j-1][1]-res1+MOD)%MOD;
            }
        }
        return (dp[zero][one][0]+dp[zero][one][1])%MOD;
    }
};
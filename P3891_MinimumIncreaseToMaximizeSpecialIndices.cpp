/* 
Problem ID : 3891 

Problem : Minimum Increase to Maximize Special Indices

Statement : You are given an integer array nums of length n.

An index i (0 < i < n - 1) is special if nums[i] > nums[i - 1] and nums[i] > nums[i + 1].

You may perform operations where you choose any index i and increase nums[i] by 1.

Your goal is to:

Maximize the number of special indices.
Minimize the total number of operations required to achieve that maximum.
Return an integer denoting the minimum total number of operations required.
*/

/* Problem Link
https://leetcode.com/problems/minimum-increase-to-maximize-special-indices/description/
*/

class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();
        vector<long long> cost(n, 0);
        for(int i=1;i<n-1;i++){
            long long t=max(nums[i-1], nums[i+1])+1LL;
            cost[i]=max(0LL, t-nums[i]);
        }
        vector<pair<int, long long>> dp(n);
        dp[0]={0, 0};
        for(int i=1;i<n;i++){
            auto skip=dp[i-1];
            pair<int, long long> tk={0, 0};
            if(i>0 && i<n-1){
                if(i>=2){
                    tk=dp[i-2];
                }
                tk.first+=1;
                tk.second+=cost[i];
            }
            if(tk.first>skip.first) dp[i]=tk;
            else if(tk.first<skip.first) dp[i]=skip;
            else dp[i]=(tk.second<skip.second)?tk:skip;
        }
        return dp[n-1].second;
    }
};
/* 
Problem ID : 3381 

Problem : Maximum Subarray Sum With Length Divisible by K

Statement : You are given an array of integers nums and an integer k.

Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.
*/

/* Problem Link
https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/?envType=daily-question&envId=2025-11-27
*/

class Solution {
public:
    using ll=long long;
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll> m(k,LLONG_MAX/2);
        ll prefix=0,ans=LLONG_MIN;
        m[k-1]=0;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            ll& ks=m[i%k];
            ans=max(ans, prefix-ks);
            ks=min(prefix,ks);
        }
        return ans;
    }
};
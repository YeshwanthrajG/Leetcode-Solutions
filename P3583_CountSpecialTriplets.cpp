/* 
Problem ID : 3583 

Problem : Count Special Triplets

Statement : You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:

0 <= i < j < k < n, where n = nums.length
nums[i] == nums[j] * 2
nums[k] == nums[j] * 2
Return the total number of special triplets in the array.

Since the answer may be large, return it modulo 109 + 7.
*/

/* Problem Link
https://leetcode.com/problems/count-special-triplets/description/?envType=daily-question&envId=2025-12-09
*/

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod=1e9+7;
        unordered_map<int, int> suffix;
        unordered_map<int, int> prefix;
        for(auto& x:nums) suffix[x]++;
        long long ans=0;
        for(auto x:nums){
            suffix[x]--;
            ans+=(long long)prefix[2*x]*suffix[2*x];
            prefix[x]+=1;
        }
        return ans%mod;
    }
};
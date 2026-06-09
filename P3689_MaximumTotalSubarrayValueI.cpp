/* 
Problem ID : 3689 

Problem : Maximum Total Subarray Value I

Statement : You are given an integer array nums of length n and an integer k.

You need to choose exactly k non-empty subarrays nums[l..r] of nums. Subarrays may overlap, and the exact 
same subarray (same l and r) can be chosen more than once.

The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

The total value is the sum of the values of all chosen subarrays.

Return the maximum possible total value you can achieve.
*/

/* Problem Link
https://leetcode.com/problems/maximum-total-subarray-value-i/description/?envType=daily-question&envId=2026-06-09
*/

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxE=nums[0], minE=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++) {
            maxE=max(maxE, 1LL*nums[i]);
            minE=min(minE, 1LL*nums[i]);
        }
        return (1LL*(maxE-minE)*k);
    }
};
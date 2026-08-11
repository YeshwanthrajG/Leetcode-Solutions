/* 
Problem ID : 2996 

Problem : Smallest Missing Integer Greater Than Sequential Prefix Sum

Statement : You are given a 0-indexed array of integers nums.

A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, 
the prefix consisting only of nums[0] is sequential.

Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the 
longest sequential prefix.
*/

/* Problem Link
https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/description/?envType=daily-question&envId=2026-08-11
*/

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> set(nums.begin(), nums.end());
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) sum+=nums[i];
            else break;
        }
        while(set.find(sum)!=set.end()) sum++;
        return sum;
    }
};
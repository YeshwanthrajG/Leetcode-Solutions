/* 
Problem ID : 560 

Problem : Subarray Sum Equals K

Statement : Given an array of integers nums and an integer k, return the total number of subarrays 
whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

/* Problem Link
https://leetcode.com/problems/subarray-sum-equals-k/description/
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int pref[n];
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=nums[i]+pref[i-1];
        unordered_map<int, int> map;
        int res=0;
        for(int i=0;i<n;i++){
            if(pref[i]==k) res++;
            if(map.find(pref[i]-k)!=map.end()) res+=map[pref[i]-k];
            map[pref[i]]++;
        }
        return res;
    }
};
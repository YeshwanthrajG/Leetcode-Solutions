/* 
Problem ID : 3364 

Problem : Minimum Positive Sum Subarray 

Statement : You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is greater than 0.

Return the minimum sum of such a subarray. If no such subarray exists, return -1.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

/* Problem Link
https://leetcode.com/problems/minimum-positive-sum-subarray/description/?envType=daily-question&envId=2026-11-14
*/

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size(), best=INT_MAX;
        vector<int> prev(n+1);
        partial_sum(nums.begin(), nums.end(), prev.begin()+1);
        for(int i=l;i<=r;i++){
            for(int j=0;i+j<=n;j++){
                int t=prev[i+j]-prev[j];
                if(t>0) best=min(best, t);
            }
        }
        return best==INT_MAX?-1:best;
    }
};
/* 
Problem ID : 643 

Problem : Maximum Average Subarray I

Statement : You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return 
this value. Any answer with a calculation error less than 10-5 will be accepted.
*/

/* Problem Link
https://leetcode.com/problems/maximum-average-subarray-i/description/
*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0.0;
        int n=nums.size();
        if(n<k) return (double)-1;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        double res=sum;
        for(int i=k;i<n;i++){
            sum-=nums[i-k];
            sum+=nums[i];
            res=max(res, sum);
        }
        return (res/(double)k);
    }
};
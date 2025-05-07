/* 
Problem ID : 53 

Problem : Maximum Subarray

Statement : Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

/* Problem Link
https://leetcode.com/problems/maximum-subarray/description/
*/

class Solution {
    public int maxSubArray(int[] nums) {
        int maxSumEndHere=nums[0];
        int maxSubArraySum=nums[0];
        for(int i=1;i<nums.length;i++)
        {
            maxSumEndHere=Math.max(maxSumEndHere+nums[i],nums[i]);
            maxSubArraySum=Math.max(maxSubArraySum, maxSumEndHere);
        }
        return maxSubArraySum;
    }
}
/* 
Problem ID : 3105 

Problem : Longest Strictly Increasing or Strictly Decreasing Subarray

Statement : You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.
*/

/* Problem Link
https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2026-11-12
*/

class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n=nums.length;
        int incCount=1,decCount=1,max=1;
        if(n==1)
            return 1;
        for (int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                decCount=1;
                incCount++;
            }

            else if(nums[i]>nums[i+1])
            {
                incCount=1;
                decCount++;
            }

            else
            {
                incCount=1;
                decCount=1;
            }

            max=Math.max(Math.max(incCount,decCount),max);
        }
        // for(int i=0;i<n-1;i++)
        // {
        //     if(nums[i]>nums[i+1])
        //         count++;

        //     else
        //         count=1;

        //     max=Math.max(count,max);
        // }
        return max;
    }
}
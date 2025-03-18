/* 
Problem ID : 2401 

Problem : Longest Nice Subarray
Statement : You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.
*/

/* Problem Link
https://leetcode.com/problems/longest-nice-subarray/description/?envType=daily-question&envId=2025-03-18
*/

class Solution {
    public int longestNiceSubarray(int[] nums) {
        int l=0,usedBits=0,maxLength=0;
        for(int i=0;i<nums.length;i++)
        {
            while((usedBits&nums[i])!=0)
            {
                usedBits^=nums[l];
                l++;
            }

            usedBits|=nums[i];
            maxLength=Math.max(maxLength,i-l+1);
        }
        return maxLength;
    }
}
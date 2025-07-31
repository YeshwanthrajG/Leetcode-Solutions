/* 
Problem ID : 2419 

Problem : Longest Subarray With Maximum Bitwise AND

Statement : You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a 
bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.
*/

/* Problem Link
https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2025-07-30
*/

class Solution {
    public int longestSubarray(int[] nums) {
        int maxVal=nums[0];
        for(int i:nums){
            maxVal=Math.max(maxVal,i);
        }

        int countMax=0;
        int currLen=0;
        
        for(int i:nums){
            if(i==maxVal)   currLen++;
            else   {
                countMax=Math.max(countMax,currLen);
                currLen=0;
            } 
        }
        return Math.max(countMax,currLen);
    }
}
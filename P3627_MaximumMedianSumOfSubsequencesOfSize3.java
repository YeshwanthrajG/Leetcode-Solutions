/* 
Problem ID : 3627 

Problem : Maximum Median Sum of Subsequences of Size 3

Statement : You are given an integer array nums with a length divisible by 3.

You want to make the array empty in steps. In each step, you can select any three elements from the array, compute 
their median, and remove the selected elements from the array.

The median of an odd-length sequence is defined as the middle element of the sequence when it is sorted in 
non-decreasing order.

Return the maximum possible sum of the medians computed from the selected elements.
*/

/* Problem Link
https://leetcode.com/problems/maximum-median-sum-of-subsequences-of-size-3/description/
*/

class Solution {
    public long maximumMedianSum(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length;
        long res=0;
        for(int i=n/3;i<n;i+=2){
            res+=nums[i];
        }
        return res;
    }
}
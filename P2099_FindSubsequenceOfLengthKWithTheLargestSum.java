/* 
Problem ID : 2099 

Problem : Find Subsequence of Length K With the Largest Sum

Statement : You are given an integer array nums and an integer k. You want to find a subsequence of nums of 
length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without 
changing the order of the remaining elements.
*/

/* Problem Link
https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/?envType=daily-question&envId=2025-06-28
*/


class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int[][] valueWithIndex = new int[nums.length][2];
        for (int i = 0; i < nums.length; i++) {
            valueWithIndex[i] = new int[]{nums[i], i}; 
        }        
        Arrays.sort(valueWithIndex, (a, b) -> b[0] - a[0]);
        Arrays.sort(valueWithIndex, 0, k, (a, b) -> a[1] - b[1]);
        
        int[] result = new int[k];
        for (int i = 0; i < k; i++) {
            result[i] = valueWithIndex[i][0]; 
        }
        
        return result;
    }
}
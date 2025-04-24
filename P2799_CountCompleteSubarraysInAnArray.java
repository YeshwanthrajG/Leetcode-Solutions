/* 
Problem ID : 2799 

Problem : Count Complete Subarrays in an Array

Statement : You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.
*/

/* Problem Link
https://leetcode.com/problems/count-complete-subarrays-in-an-array/?envType=daily-question&envId=2025-04-24
*/

class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> unique = new HashSet<>();
        for (int num : nums) unique.add(num);
        int totalDistinct = unique.size(), count = 0, n = nums.length;

        for (int i = 0; i < n; i++) {
            Set<Integer> seen = new HashSet<>();
            for (int j = i; j < n; j++) {
                seen.add(nums[j]);
                if (seen.size() == totalDistinct) {
                    count += n - j;
                    break;
                }
            }
        }

        return count;
    }
}
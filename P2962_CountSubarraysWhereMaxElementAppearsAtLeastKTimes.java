/* 
Problem ID : 2962 

Problem : Count Subarrays Where Max Element Appears at Least K Times

Statement : You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.
*/

/* Problem Link
https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2025-04-29
*/

class Solution {
    public long countSubarrays(int[] nums, int k) {
        int maxi = Integer.MIN_VALUE;
        for (int num : nums) maxi = Math.max(maxi, num);
        int left = 0;
        long maxiOccurence = 0;
        long res = 0;
        for (int right = 0; right < nums.length; right++) {
            if (nums[right] == maxi) maxiOccurence++;
            while (maxiOccurence >= k) {
                if (nums[left] == maxi) maxiOccurence--;
                left++;
            }
            res += left;
        }
        return res;
    }
}
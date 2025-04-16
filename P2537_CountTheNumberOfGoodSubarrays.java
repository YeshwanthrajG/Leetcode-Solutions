/* 
Problem ID : 2537 

Problem : Count the Number of Good Subarrays

Statement : Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.
*/

/* Problem Link
https://leetcode.com/problems/count-the-number-of-good-subarrays/description/?envType=daily-question&envId=2025-04-16
*/

class Solution {
    public long countGood(int[] nums, int k) {
        Map<Integer, Integer> mpp = new HashMap<>();
        long cnt = 0; int left = 0;
        for (int i = 0; i < nums.length; i++) {
            k -= mpp.getOrDefault(nums[i], 0);
            mpp.put(nums[i], mpp.getOrDefault(nums[i], 0) + 1);
            while (k <= 0) {
                mpp.put(nums[left], mpp.get(nums[left]) - 1);
                k += mpp.get(nums[left++]);
            }
            cnt += left;
        }
        return cnt;
    }
}
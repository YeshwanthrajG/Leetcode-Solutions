/* 
Problem ID : 2563 

Problem : Count the Number of Fair Pairs

Statement : Given a 0-indexed integer array nums of size n and two integers lower and upper, 
return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
*/

/* Problem Link
https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2025-04-19
*/

class Solution {
    public long countAtMost(int[] nums, long comp) {
        long ans = 0;
        int j = nums.length - 1;
        for (int i = 0; i < j; i++) {
            while (i < j && nums[i] + nums[j] > comp) j--;
            ans += j - i;
        }
        return ans;
    }

    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        return countAtMost(nums, upper) - countAtMost(nums, lower - 1);
    }
}
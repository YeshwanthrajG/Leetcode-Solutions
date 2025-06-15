/* 
Problem ID : 2616 

Problem : Minimize the Maximum Difference of Pairs

Statement : You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums 
such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than 
once amongst the p pairs.

Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, 
where |x| represents the absolute value of x.

Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.
*/

/* Problem Link
https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/?envType=daily-question&envId=2025-06-13
*/

class Solution {
    public int minimizeMax(int[] nums, int p) {
        if (p == 0) return 0;
        Arrays.sort(nums);
        int n = nums.length, left = 0, right = nums[n-1] - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2, pairs = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i] - nums[i-1] <= mid) {
                    pairs++;
                    i++;
                }
            }
            if (pairs >= p) right = mid;
            else left = mid + 1;
        }
        return left;
    }
}
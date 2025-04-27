/* 
Problem ID : 3392 

Problem : Count Subarrays of Length Three With a Condition

Statement : Given an integer array nums, return the number of subarrays of length 3 such that 
the sum of the first and third numbers equals exactly half of the second number.

*/

/* Problem Link
https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/?envType=daily-question&envId=2025-04-27
*/

class Solution {
    public int countSubarrays(int[] nums) {
        int count = 0;
        for (int i = 0; i + 2 < nums.length; i++) {
            if (2 * (nums[i] + nums[i + 2]) == nums[i + 1]) {
                count++;
            }
        }
        return count;
    }
}
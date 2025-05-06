/* 
Problem ID : 1920 

Problem : Build Array from Permutation

Statement : Given a zero-based permutation nums (0-indexed), build an array ans of the same length where 
ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).
*/

/* Problem Link
https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06
*/

class Solution {
    public int[] buildArray(int[] nums) {
        for (int i = 0; i < nums.length; i++)
            nums[i] += (1024 * (nums[nums[i]] % 1024));
        
        for (int i = 0; i < nums.length; i++)
            nums[i] /= 1024;
        
        return nums;
    }
}
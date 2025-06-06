/* 
Problem ID : 2176 

Problem : Count Equal and Divisible Pairs in an Array

Statement : Given a 0-indexed integer array nums of length n and an integer k, return the number of 
pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.
*/

/* Problem Link
https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11
*/

class Solution {
    public int countPairs(int[] nums, int k) {
        int pairs = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    pairs++;
                }
            }
        }
        return pairs;
    }
}
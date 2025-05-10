/* 
Problem ID : 1400 

Problem : Minimum Equal Sum of Two Arrays After Replacing Zeros

Statement : You are given two arrays nums1 and nums2 consisting of positive integers.

You have to replace all the 0's in both arrays with strictly positive integers such that the sum of 
elements of both arrays becomes equal.

Return the minimum equal sum you can obtain, or -1 if it is impossible.
*/

/* Problem Link
https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11
*/

class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long nums1Zeroes = 0, nums2Zeroes = 0,sum1 = 0, sum2 = 0;
        for(int i : nums1){
            if(i == 0) nums1Zeroes++;
            sum1 += i;
        }

        for(int i : nums2){
            if(i == 0) nums2Zeroes++;
            sum2 += i;
        }

        long min1 = sum1 + nums1Zeroes;
        long min2 = sum2 + nums2Zeroes;

        if(nums1Zeroes == 0 && nums2Zeroes == 0){
            return sum1 == sum2 ? sum1 : -1;
        }else if(nums1Zeroes == 0){
            return sum2 + nums2Zeroes <=sum1 ?sum1 : -1;
        }else if (nums2Zeroes == 0){
            return sum1 + nums1Zeroes <= sum2 ? sum2 : -1;
        }
        return Math.max(min1, min2);
    }
}
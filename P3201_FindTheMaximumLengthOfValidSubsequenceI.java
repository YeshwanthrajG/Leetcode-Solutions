/* 
Problem ID : 3201 

Problem : Find the Maximum Length of Valid Subsequence I

Statement : You are given an integer array nums.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting some or no elements without 
changing the order of the remaining elements.
*/

/* Problem Link
https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/?envType=daily-question&envId=2025-07-16
*/

class Solution {
    public int maximumLength(int[] nums) {
        int oddCount=0;
        int evenCount=0;
        for(int i:nums){
            if(i%2==0)  evenCount++;
            else    oddCount++;
        }
        int oddDP=0,evenDP=0;
        for(int i:nums){
            if(i%2==0)  evenDP=Math.max(evenDP,oddDP+1);
            else    oddDP=Math.max(oddDP,evenDP+1);
        }
        return Math.max(Math.max(oddCount,evenCount),Math.max(oddDP,evenDP));
    }
}
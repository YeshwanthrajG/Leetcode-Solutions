/* 
Problem ID : 1863 

Problem : Sum of All Subset XOR Totals

Statement : The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array 
is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
*/

/* Problem Link
https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2025-04-05
*/

class Solution {
    public int subsetXORSum(int[] nums) {
        int res=0;
        for(int i:nums)
            res|=i;
        return res*(1<<(nums.length-1));
    }
}
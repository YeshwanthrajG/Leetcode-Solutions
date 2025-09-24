/* 
Problem ID : 3688 

Problem : Bitwise OR of Even Numbers in an Array

Statement : You are given an integer array nums.

Return the bitwise OR of all even numbers in the array.

If there are no even numbers in nums, return 0.
*/

/* Problem Link
https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/description/
*/

class Solution {
    public int evenNumberBitwiseORs(int[] nums) {
        int val=0;
        for(int i:nums){
            if(i%2==0){
                val|=i;
            }
        }
        return val;
    }
}
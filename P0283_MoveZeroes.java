/* 
Problem ID : 283 

Problem : Move Zeroes

Statement : Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the 
non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

/* Problem Link
https://leetcode.com/problems/move-zeroes/description/
*/

class Solution {
    public void moveZeroes(int[] nums) {
        int left=0,right=0;
        while(right<nums.length){
            if(nums[right]!=0){
                int temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
                left++;
            }
            right++;
        }
    }
}
/* 
Problem ID : 215 

Problem : Kth Largest Element in an Array

Statement : Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/

/* Problem Link
https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/

class Solution {
    public int findKthLargest(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[nums.length-k];
    }
}
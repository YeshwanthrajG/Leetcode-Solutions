/* 
Problem ID : 33 

Problem : Search in Rotated Sorted Array

Statement : There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k 
(1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], 
nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices 
and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it 
is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

/* Problem Link
https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=daily-question&envId=2026-05-22
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0, high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums.back()) low=mid+1;
            else high=mid;
        }
        int r=low;
        low=0, high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int idx=(mid+r)%n;
            if(nums[idx]==target) return idx;
            if(nums[idx]<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};
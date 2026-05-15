/* 
Problem ID : 153 

Problem : Find Minimum in Rotated Sorted Array

Statement : Suppose an array of length n sorted in ascending order is rotated between 1 and n times. 
For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], 
a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/

/* Problem Link
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=daily-question&envId=2026-05-15
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1, m=0;
        while(l<r){
            m=l+(r-l)/2;
            if(nums[m]<nums[r]){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        return nums[l];
    }
};
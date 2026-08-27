/* 
Problem ID : 2089 

Problem : Find Target Indices After Sorting Array

Statement : You are given a 0-indexed integer array nums and a target element target.

A target index is an index i such that nums[i] == target.

Return a list of the target indices of nums after sorting nums in non-decreasing order. 
If there are no target indices, return an empty list. The returned list must be sorted in 
increasing order.
*/

/* Problem Link
https://leetcode.com/problems/find-target-indices-after-sorting-array/description/
*/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        int l=0, h=0;
        for(int i:nums){
            if(i>target) h++;
            else if(i<target) l++;
        }
        for(int i=l;i<nums.size()-h;i++){
            res.push_back(i);
        }
        return res;
    }
};
/* 
Problem ID : 1827 

Problem : Minimum Operations to Make the Array Increasing

Statement : You are given an integer array nums (0-indexed). In one operation, you can choose an element 
of the array and increment it by 1.

For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
Return the minimum number of operations needed to make nums strictly increasing.

An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1. An array of 
length 1 is trivially strictly increasing.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/description/?envType=problem-list-v2&envId=n11ydiyj
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int temp=nums[i-1]-nums[i]+1;
                ops+=temp;
                nums[i]+=temp;
            }
        }
        return ops;
    }
};
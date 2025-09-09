/* 
Problem ID : 3674 

Problem : Minimum Operations to Equalize Array

Statement : You are given an integer array nums of length n.

In one operation, choose any subarray nums[l...r] (0 <= l <= r < n) and replace each element in that subarray with the 
bitwise AND of all elements.

Return the minimum number of operations required to make all elements of nums equal.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-equalize-array/
*/

class Solution {
    public int minOperations(int[] nums) {
        boolean allEqual=true;
        int n=nums.length;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                allEqual=false;
            }
        }
        if(allEqual) return 0;
        int res=nums[0];
        for(int i=1;i<n;i++){
            res&=nums[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=res){
                return 1;
            }
        }
        return 0;
    }
}
/* 
Problem ID : 3818 

Problem : Minimum Prefix Removal to Make Array Strictly Increasing

Statement : You are given an integer array nums.

You need to remove exactly one prefix (possibly empty) from nums.

Return an integer denoting the minimum length of the removed prefix such that the remaining array 
is strictly increasing.
*/

/* Problem Link
https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/description/
*/

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        while(i>0 && nums[i-1]<nums[i]){
            i--;
        }
        return i;
    }
};
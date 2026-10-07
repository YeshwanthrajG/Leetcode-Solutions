/* 
Problem ID : 3880 

Problem : Minimum Absolute Difference Between Two Values

Statement : You are given an integer array nums consisting only of 0, 1, and 2.

A pair of indices (i, j) is called valid if nums[i] == 1 and nums[j] == 2.

Return the minimum absolute difference between i and j among all valid pairs. If no valid pair exists, 
return -1.

The absolute difference between indices i and j is defined as abs(i - j).
*/

/* Problem Link
https://leetcode.com/problems/minimum-absolute-difference-between-two-values/description/
*/

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        int minDiff=INT_MAX;
        int last1=-1, last2=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                last1=i;
                if(last2!=-1){
                    minDiff=min(minDiff, abs(last1-last2));
                }
            }
            else if(nums[i]==2){
                last2=i;
                if(last1!=-1){
                    minDiff=min(minDiff, abs(last1-last2));
                }
            }
        }
        return (minDiff==INT_MAX)?-1:minDiff;
    }
};
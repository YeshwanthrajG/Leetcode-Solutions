/* 
Problem ID : 3774 

Problem : Absolute Difference Between Maximum and Minimum K Elements

Statement : You are given an integer array nums and an integer k.

Find the absolute difference between:

the sum of the k largest elements in the array; and
the sum of the k smallest elements in the array.
Return an integer denoting this difference.
*/

/* Problem Link
https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/description/
*/

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxK=0,minK=0;
        for(int i=0;i<k;i++) minK+=nums[i];
        int n=nums.size();
        for(int i=n-k;i<n;i++) maxK+=nums[i];
        return abs(maxK-minK);
    }
};
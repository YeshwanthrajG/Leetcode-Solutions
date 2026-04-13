/* 
Problem ID : 1848 

Problem : Minimum Distance to the Target Element

Statement : Given an integer array nums (0-indexed) and two integers target and start, find an index i such 
that nums[i] == target and abs(i - start) is minimized. Note that abs(x) is the absolute value of x.

Return abs(i - start).

It is guaranteed that target exists in nums.
*/

/* Problem Link
https://leetcode.com/problems/minimum-distance-to-the-target-element/description/?envType=daily-question&envId=2026-04-13
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                res=min(res, abs(i-start));
            }
        }
        return res;
    }
};
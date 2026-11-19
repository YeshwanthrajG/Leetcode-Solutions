/* 
Problem ID : 2567 

Problem : Minimum Score by Changing Two Elements

Statement : You are given an integer array nums.

The low score of nums is the minimum absolute difference between any two integers.
The high score of nums is the maximum absolute difference between any two integers.
The score of nums is the sum of the high and low scores.
Return the minimum score after changing two elements of nums.
*/

/* Problem Link
https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/?envType=daily-question&envId=2026-11-19
*/

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        return (min({nums[n-1]-nums[2], nums[n-2]-nums[1], nums[n-3]-nums[0]}));
    }
};
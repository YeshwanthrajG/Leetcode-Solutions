/* 
Problem ID : 976 

Problem : Largest Perimeter Triangle

Statement : Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, 
formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.
*/

/* Problem Link
https://leetcode.com/problems/largest-perimeter-triangle/description/?envType=daily-question&envId=2025-09-28
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i+1]+nums[i+2]>nums[i]) return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};
/* 
Problem ID : 136 

Problem : Single Number

Statement : Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

/* Problem Link
https://leetcode.com/problems/single-number/description/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num=nums[0];
        for(int i=1;i<nums.size();i++) num^=nums[i];
        return num;
    }
};
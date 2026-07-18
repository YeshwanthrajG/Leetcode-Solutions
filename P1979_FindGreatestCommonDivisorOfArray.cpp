/* 
Problem ID : 1979 

Problem : Find Greatest Common Divisor of Array

Statement : Given an integer array nums, return the greatest common divisor of the smallest number and 
largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/

/* Problem Link
https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/?envType=daily-question&envId=2026-07-18
*/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minV=nums[0], maxV=nums[0];
        for(int i=1;i<nums.size();i++){
            minV=min(minV, nums[i]);
            maxV=max(maxV, nums[i]);
        }
        for(int i=minV;i>=1;i--){
            if((minV%i==0) && (maxV%i==0)) return i;
        }
        return 1;
    }
};
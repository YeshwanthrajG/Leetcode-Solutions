/* 
Problem ID : 3024 

Problem : Type of Triangle

Statement : You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

A triangle is called equilateral if it has all sides of equal length.
A triangle is called isosceles if it has exactly two sides of equal length.
A triangle is called scalene if all its sides are of different lengths.
Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.
*/

/* Problem Link
https://leetcode.com/problems/type-of-triangle/description/?envType=daily-question&envId=2025-05-19
*/

class Solution {
    public String triangleType(int[] nums) {
        Arrays.sort(nums);
        if(nums[0]+nums[1]<=nums[2])
            return "none";

        if((nums[0]!=nums[1])&&(nums[0]!=nums[2])&&(nums[1]!=nums[2]))
            return "scalene";
        
        if((nums[0]==nums[1])&&(nums[0]==nums[2])&&(nums[1]==nums[2]))
            return "equilateral";
        
        return "isosceles";
    }
}
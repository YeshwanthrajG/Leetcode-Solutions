/* 
Problem ID : 2559 

Problem : Number of Ways to Split Array

Statement : You are given a 0-indexed integer array nums of length n.
nums contains a valid split at index i if the following are true:
The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.
*/

/* Problem Link
https://leetcode.com/problems/number-of-ways-to-split-array/description/?envType=daily-question&envId=2025-01-03
*/

class NumberofWaystoSplitArray {
    public int waysToSplitArray(int[] nums) {
        int n=nums.length;
        long left=0;
        long right=0;
        int result=0;
        for(int i:nums)
            right+=i;

        for(int i=0;i<n-1;i++)
        {
            left+=nums[i];
            right-=nums[i];
            if(left>=right)
                result++;
        }
        return result;        
    }
}
/* 
Problem ID : 3191 

Problem : Minimum Operations to Make Binary Array Elements Equal to One I

Statement : You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, 
return -1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/?envType=daily-question&envId=2025-03-19
*/

class Solution {
    public int minOperations(int[] nums) {
        int flip=0;
        int n=nums.length;
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]==0)
            {
                nums[i]^=1;
                nums[i+1]^=1;
                nums[i+2]^=1;
                flip++;
            }
        }
        if(nums[n-1]==1&&nums[n-2]==1)
            return flip;
        return -1;
    }
}
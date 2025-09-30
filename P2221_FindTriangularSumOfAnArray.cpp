/* 
Problem ID : 2221 

Problem : Find Triangular Sum of an Array

Statement : You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9 
(inclusive).

The triangular sum of nums is the value of the only element present in nums after the following process 
terminates:

Let nums comprise of n elements. If n == 1, end the process. Otherwise, create a new 0-indexed integer 
array newNums of length n - 1.
For each index i, where 0 <= i < n - 1, assign the value of newNums[i] as (nums[i] + nums[i+1]) % 10, 
where % denotes modulo operator.
Replace the array nums with newNums.
Repeat the entire process starting from step 1.
Return the triangular sum of nums.
*/

/* Problem Link
https://leetcode.com/problems/find-triangular-sum-of-an-array/description/?envType=daily-question&envId=2025-09-30
*/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<i;j++){
                nums[j]=(nums[j]+nums[j+1])%10;
            }
        }
        return nums[0];
    }
};
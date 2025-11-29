/* 
Problem ID : 3512 

Problem : Minimum Operations to Make Array Sum Divisible by K

Statement : You are given an integer array nums and an integer k. 
You can perform the following operation any number of times:

Select an index i and replace nums[i] with nums[i] - 1.
Return the minimum number of operations required to make the sum of the array divisible by k.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/?envType=daily-question&envId=2025-11-29
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(int i:nums) sum+=i;
        return (sum%k);
    }
};
/* 
Problem ID : 3379 

Problem : Transformed Array

Statement : You are given an integer array nums that represents a circular array. 
Your task is to create a new array result of the same size, following these rules:

For each index i (where 0 <= i < nums.length), perform the following independent actions:
If nums[i] > 0: Start at index i and move nums[i] steps to the right in the circular array. 
Set result[i] to the value of the index where you land.
If nums[i] < 0: Start at index i and move abs(nums[i]) steps to the left in the circular array. 
Set result[i] to the value of the index where you land.
If nums[i] == 0: Set result[i] to nums[i].
Return the new array result.

Note: Since nums is circular, moving past the last element wraps around to the beginning, 
and moving before the first element wraps back to the end.
*/

/* Problem Link
https://leetcode.com/problems/transformed-array/description/?envType=daily-question&envId=2026-02-05
*/

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int val=nums[i];
            if(nums[i]>0){
                res[i]=nums[(i+(nums[i]))%n];
            }
            else{
                res[i]=nums[((i+nums[i])%n+n)%n];
            }
        }
        return res;
    }
};
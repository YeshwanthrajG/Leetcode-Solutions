/* 
Problem ID : 3701 

Problem : Compute Alternating Sum

Statement : You are given an integer array nums.

The alternating sum of nums is the value obtained by adding elements at even indices and 
subtracting elements at odd indices. That is, nums[0] - nums[1] + nums[2] - nums[3]...

Return an integer denoting the alternating sum of nums.
*/

/* Problem Link
https://leetcode.com/problems/compute-alternating-sum/description/
*/

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) res+=nums[i];
            else res-=nums[i];
        }
        return res;
    }
};
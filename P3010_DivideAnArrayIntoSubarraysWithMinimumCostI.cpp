/* 
Problem ID : 3010 

Problem : Divide an Array Into Subarrays With Minimum Cost I

Statement : You are given an array of integers nums of length n.

The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 
while the cost of [3,4,1] is 3.

You need to divide nums into 3 disjoint contiguous subarrays.

Return the minimum possible sum of the cost of these subarrays.
*/

/* Problem Link
https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01
*/

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0];
        int min1=INT_MAX, min2=min1;
        for(int i=1;i<n;i++){
            if(min1>nums[i]){
                min2=min1;
                min1=nums[i];
            }
            else if(min2>nums[i]) min2=nums[i];
        }
        res+=min1+min2;
        return res;
    }
};
/* 
Problem ID : 3804 

Problem : Number of Centered Subarrays

Statement : You are given an integer array nums.

A subarray of nums is called centered if the sum of its elements is equal to at least one element within 
that same subarray.

Return the number of centered subarrays of nums.
*/

/* Problem Link
https://leetcode.com/problems/number-of-centered-subarrays/description/
*/

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            long long sum=0;
            unordered_set<long long> ele;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                ele.insert(nums[j]);
                if(ele.count(sum)) res++;
            }
            
        }
        return res;
    }
};
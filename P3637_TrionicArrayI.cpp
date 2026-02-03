/* 
Problem ID : 3637 

Problem : Trionic Array I

Statement : You are given an integer array nums of length n.

An array is trionic if there exist indices 0 < p < q < n − 1 such that:

nums[0...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...n − 1] is strictly increasing.
Return true if nums is trionic, otherwise return false.
*/

/* Problem Link
https://leetcode.com/problems/trionic-array-i/description/?envType=daily-question&envId=2026-02-03
*/

class Solution {
public:
    bool isArrayDecreasing(vector<int> &nums, int peak, int valley){
        if(peak==0 || valley==nums.size()-1) return false;
        for(int i=peak;i<valley;i++){
            if(nums[i]<=nums[i+1]) return false;
        }
        return true;
    }
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int peak=n-1,valley=0;
        for(int i=0;i<n-1;i++){
            if(peak==n-1 && nums[i]>=nums[i+1]) peak=i;
            if(valley==0 && nums[n-i-1]<=nums[n-i-2]) valley=n-i-1;
            if(peak<valley) 
                return isArrayDecreasing(nums,peak,valley);
        }
        return false;
    }
};
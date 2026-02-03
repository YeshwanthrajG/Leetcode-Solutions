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
    public boolean isTrionic(int[] nums) {
        int n=nums.length;
        if(n<3) return false;

        int i=0;
        while(i+1<n&&nums[i]<nums[i+1]) i++;
        if(i==0||i==n-1) return false;
        int p=i;
        while(i+1<n&&nums[i]>nums[i+1]) i++;
        if(i==p||i==n-1) return false;
        int q=i;
        while(i+1<n&&nums[i]<nums[i+1]) i++;
        return i==n-1;
    }
}
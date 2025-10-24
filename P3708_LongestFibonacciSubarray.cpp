/* 
Problem ID : 3708 

Problem : Longest Fibonacci Subarray

Statement : You are given an array of positive integers nums.

A Fibonacci array is a contiguous sequence whose third and subsequent terms each equal the sum of 
the two preceding terms.

Return the length of the longest Fibonacci subarray in nums.

Note: Subarrays of length 1 or 2 are always Fibonacci.
*/

/* Problem Link
https://leetcode.com/problems/longest-fibonacci-subarray/description/
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int maxL=2,currL=2;
        for(int i=2;i<n;i++){
            if(nums[i]==nums[i-1]+nums[i-2]){
                currL++;
            }
            else currL=2;
            maxL=max(maxL,currL);
        }
        return maxL;
    }
};
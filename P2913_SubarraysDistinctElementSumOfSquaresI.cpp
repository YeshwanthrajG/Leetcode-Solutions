/* 
Problem ID : 2913 

Problem : Subarrays Distinct Element Sum of Squares I

Statement : You are given a 0-indexed integer array nums.

The distinct count of a subarray of nums is defined as:

Let nums[i..j] be a subarray of nums consisting of all the indices from i to j such that 
0 <= i <= j < nums.length. Then the number of distinct values in nums[i..j] is called 
the distinct count of nums[i..j].
Return the sum of the squares of distinct counts of all subarrays of nums.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

/* Problem Link
https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/?envType=daily-question&envId=2026-10-15
*/

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            unordered_set<int> set;
            for(int j=i;j<n;j++){
                set.insert(nums[j]);
                int k=set.size();
                res+=(k*k);
            }
        }
        return res;
    }
};
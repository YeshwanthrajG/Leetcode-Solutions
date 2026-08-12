/* 
Problem ID : 2958 

Problem : Length of Longest Subarray With at Most K Frequency

Statement : You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

/* Problem Link
https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2026-08-12
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int, int> map;
        map.reserve(n);
        for(int i=0, j=0;j<n;j++){
            int temp=nums[j];
            auto it=map.find(temp);
            int &pnt=(it==map.end())?map[temp]=1:++(it->second);
            while(pnt>k) map[nums[i++]]--;
            count=max(count, j-i+1);
        }
        return count;
    }
};
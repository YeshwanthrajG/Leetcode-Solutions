/* 
Problem ID : 2488 

Problem : Count Subarrays With Median K

Statement : You are given an array nums of size n consisting of distinct integers from 1 to n and a 
positive integer k.

Return the number of non-empty subarrays in nums that have a median equal to k.

Note:

The median of an array is the middle element after sorting the array in ascending order. If the array 
is of even length, the median is the left middle element.
For example, the median of [2,3,1,4] is 2, and the median of [8,4,3,5,1] is 4.
A subarray is a contiguous part of an array.
*/

/* Problem Link
https://leetcode.com/problems/count-subarrays-with-median-k/description/
*/

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int n=nums.size();
        m[0]=1;
        bool K=false;
        int x=0, total=0;
        for(int i:nums){
            if(i<k) x--;
            else if(i>k) x++;
            else K=true;
            if(K){
                total+=m[x]+m[x-1];
            }
            else m[x]++;
        }
        return total;
    }
};
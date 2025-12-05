/* 
Problem ID : 3432 

Problem : Count Partitions with Even Sum Difference

Statement : You are given an integer array nums of length n.

A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty 
subarrays such that:

Left subarray contains indices [0, i].
Right subarray contains indices [i + 1, n - 1].
Return the number of partitions where the difference between the sum of the left and right subarrays 
is even.
*/

/* Problem Link
https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/?envType=daily-question&envId=2025-12-05
*/

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int ls=0,count=0;
        for(int i=0;i<n-1;i++){
            ls+=nums[i];
            int rs=sum-ls;
            if((ls%2)==(rs%2)) count++;
        }
        return count;
    }
};
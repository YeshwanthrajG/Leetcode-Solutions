/* 
Problem ID : 1658 

Problem : Minimum Operations to Reduce X to Zero

Statement : You are given an integer array nums and an integer x. In one operation, you can either 
remove the leftmost or the rightmost element from the array nums and subtract its value from x. 
Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/?envType=daily-question&envId=2026-09-23
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int tot=accumulate(nums.begin(), nums.end(), 0);
       int n=nums.size(), k=tot-x;
       if(k<0) return -1;
       if(k==0) return n;
       int l=0, sum=0, res=-1;
       for(int r=0;r<n;r++){
        sum+=nums[r];
        while(l<=r && sum>k) sum-=nums[l++];
        if(sum==k) res=max(res, (r-l+1));
       }
       return (res==-1)?-1:n-res;
    }
};
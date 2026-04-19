/* 
Problem ID : 3833 

Problem : Count Dominant Indices

Statement : You are given an integer array nums of length n.

An element at index i is called dominant if: nums[i] > average(nums[i + 1], nums[i + 2], ..., nums[n - 1])

Your task is to count the number of indices i that are dominant.

The average of a set of numbers is the value obtained by adding all the numbers together and dividing the 
sum by the total number of numbers.

Note: The rightmost element of any array is not dominant.
*/

/* Problem Link
https://leetcode.com/problems/count-dominant-indices/description/
*/

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        if(n<=1) return 0;
        vector<int> s(n,0);
        s[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            s[i]=s[i+1]+nums[i];
        }
        for(int i=0;i<n-1;i++){
            int rS=s[i+1];
            int rC=n-i-1;
            if((long long)nums[i]*rC>rS) res++;
        }
        return res;
    }
};
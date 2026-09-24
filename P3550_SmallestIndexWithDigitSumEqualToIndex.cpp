/* 
Problem ID : 3550 

Problem : Smallest Index With Digit Sum Equal to Index

Statement : You are given an integer array nums.

Return the smallest index i such that the sum of the digits of nums[i] is equal to i.

If no such index exists, return -1.
*/

/* Problem Link
https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/description/?envType=daily-question&envId=2026-09-24
*/

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(digitSum(nums[i])==i) return i;
        }
        return -1;
    }
    int digitSum(int n){
        if(n<=9) return n;
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
};
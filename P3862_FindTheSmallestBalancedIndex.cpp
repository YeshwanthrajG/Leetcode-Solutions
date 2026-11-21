/* 
Problem ID : 3862 

Problem : Find the Smallest Balanced Index

Statement : You are given an integer array nums.

An index i is balanced if the sum of elements strictly to the left of i equals the product of elements strictly to the right of i.

If there are no elements to the left, the sum is considered as 0. Similarly, if there are no elements to the right, the product is considered as 1.

Return an integer denoting the smallest balanced index. If no balanced index exists, return -1.
*/

/* Problem Link
https://leetcode.com/problems/find-the-smallest-balanced-index/description/
*/

class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n=nums.size();
        long long LIMIT=1e14;
        vector<long long> suff(n);
        long long prod=1;
        for(int i=n-1;i>=0;i--){
            if(prod>LIMIT/nums[i]) prod=LIMIT;
            else prod*=nums[i];
            suff[i]=prod;
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            long long right=(i==n-1)?1:suff[i+1];
            if(sum==right) return i;
            sum+=nums[i];
        }
        return -1;
    }
};
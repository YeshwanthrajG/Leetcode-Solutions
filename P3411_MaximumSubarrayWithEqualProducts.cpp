/* 
Problem ID : 3411 

Problem : Maximum Subarray With Equal Products

Statement : You are given an array of positive integers nums.

An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:

prod(arr) is the product of all elements of arr.
gcd(arr) is the GCD of all elements of arr.
lcm(arr) is the LCM of all elements of arr.
Return the length of the longest product equivalent subarray of nums.
*/

/* Problem Link
https://leetcode.com/problems/maximum-subarray-with-equal-products/description/?envType=daily-question&envId=2026-11-24
*/

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res=2, l=0, prod=1;
        for(int r=0;r<nums.size();r++){
            int t=nums[r];
            while(gcd(prod, t)>1) prod/=nums[l++];
            prod*=t;
            res=max(res, r-l+1);
        }
        return res;
    }
};
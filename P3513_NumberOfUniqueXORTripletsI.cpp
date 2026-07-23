/* 
Problem ID : 3513 

Problem : Number of Unique XOR Triplets I

Statement : You are given an integer array nums of length n, where nums is a permutation of the numbers 
in the range [1, n].

A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] 
where i <= j <= k.

Return the number of unique XOR triplet values from all possible triplets (i, j, k).
*/

/* Problem Link
https://leetcode.com/problems/number-of-unique-xor-triplets-i/description/?envType=daily-question&envId=2026-07-23
*/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int res=0;
        for(int num:nums){
            res|=num;
        }
        return res+1;
    }
};
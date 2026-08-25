/* 
Problem ID : 3718 

Problem : Smallest Missing Multiple of K

Statement : Given an integer array nums and an integer k, return the smallest positive multiple of k 
that is missing from nums.

A multiple of k is any positive integer divisible by k.
*/

/* Problem Link
https://leetcode.com/problems/smallest-missing-multiple-of-k/description/?envType=daily-question&envId=2026-08-25
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(), nums.end());
        int count=k;
        while(set.count(count)){
            count+=k;
        }
        return count;
    }
};
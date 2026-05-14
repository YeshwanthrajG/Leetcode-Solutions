/* 
Problem ID : 2784 

Problem : Check if Array is Good

Statement : You are given an integer array nums. We consider an array good if it is a permutation of an 
array base[n].

base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to 
n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

Return true if the given array is good, otherwise return false.

Note: A permutation of integers represents an arrangement of these numbers.
*/

/* Problem Link
https://leetcode.com/problems/check-if-array-is-good/description/?envType=daily-question&envId=2026-05-14
*/

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size()-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=(i+1)) return false;
        }
        if(nums[n]!=n) return false;
        return true;
    }
};
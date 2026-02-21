/* 
Problem ID : 2859 

Problem : Sum of Values at Indices With K Set Bits

Statement : You are given a 0-indexed integer array nums and an integer k.

Return an integer that denotes the sum of elements in nums whose corresponding indices 
have exactly k set bits in their binary representation.

The set bits in an integer are the 1's present when it is written in binary.

For example, the binary representation of 21 is 10101, which has 3 set bits.
*/

/* Problem Link
https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/description/
*/

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(__builtin_popcount(i)==k) sum+=nums[i];
        }
        return sum;
    }
};